/* $Id: procstream.h,v 1.10 2011-05-02 08:48:59 matuzaki Exp $
 *
 *    Copyright (c) 2005, Yusuke Miyao
 *
 *    You may distribute this file under the terms of the Artistic License.
 */

#ifndef __procstream_h
#define __procstream_h

#include "lconfig.h"
#include "profile.h"
#include <ios>
#include <iostream>
#include <istream>
#include <ostream>
#include <string>

#ifdef LILFES_WIN_
#include <Windows.h>
#else
#include <termios.h>
#endif

#ifdef HAVE_SYS_TYPES_H
#  include <sys/types.h>
#endif // HAVE_SYS_TYPES_H

#ifdef HAVE_SYS_WAIT_H
#  include <sys/wait.h>
#endif // HAVE_SYS_WAIT_H

#ifdef HAVE_STROPTS_H
#  include <stropts.h>
#endif // HAVE_STROPTS_H

#ifdef HAVE_FCNTL_H
#  include <fcntl.h>
#endif // HAVE_FCNTL_H

#ifdef HAVE_SYS_IOCTL_H
#  include <sys/ioctl.h>
#endif // HAVE_SYS_IOCTL_H

#ifdef HAVE_PTY_H
#  include <pty.h>
#endif // HAVE_PTH_H

#ifdef HAVE_UTIL_H
#  include <util.h>
#endif // HAVE_UTIL_H

namespace lilfes {

//////////////////////////////////////////////////////////////////////
////
//// streambuf for process communication
////
//////////////////////////////////////////////////////////////////////
#ifdef LILFES_WIN_

/// <summary>
/// �v���Z�X�ɑ΂�����o�͏����ƃf�[�^�̃o�b�t�@�����O���s���N���X�B
/// </summary>
class pty_stream_buf : public std::streambuf
{
public:
	// lilfes�̕����ɍ��킹���^�C�v��`�B
	typedef size_t size_type;
	typedef char char_type;

	/// <summary>
	/// �o�b�t�@�T�C�Y���w�肵�����������s���B
	/// </summary>
	/// <remarks>
	/// �o�b�t�@�T�C�Y�͏ȗ��\�B
	/// �ȗ����́A�f�t�H���g��4096�o�C�g���m�ۂ����B
	/// </reamrks>
	/// <param name="size">�o�b�t�@�T�C�Y�B</param>
	pty_stream_buf(size_type size = DEFAULT_BUFSIZE)
		: buffer(0), buffered(false)
	{
		// �v���Z�X����������
		ZeroMemory(&(this->process), sizeof(PROCESS_INFORMATION));
	}

	/// <summary>
	/// �X�g���[������āA�o�b�t�@�Ɋ��蓖�Ă�ꂽ���������������B
	/// </summary>
	virtual ~pty_stream_buf()
	{
		this->close();
	}

	/// <summary>
	/// �t�@�C���f�X�N���v�^���擾����B
	/// </summary>
	int get_fd() const
	{
		return 0;
	}

	/// <summary>
	/// �v���Z�XID���擾����B
	/// </summary>
	/// <returns>�v���Z�XID�B</returns>
	int get_pid() const
	{
		return this->process.dwProcessId;
	}

	/// <summary>
	/// �v���Z�X�����s����Ă��邩���ׂ�B
	/// </summary>
	/// <returns>���s����Ă��邩�������^�U�l�B</returns>
	virtual bool is_open() const
	{
		return (this->process.dwProcessId != 0);
	}

	/// <summary>
	/// �v���Z�X�n���h�����擾����B
	/// </summary>
	/// <returns>�v���Z�X�n���h���B</returns>
	HANDLE getProcess()
	{
		return this->process.hProcess;
	}

	/// <summary>
	/// �v���Z�X���I�����ăX�g���[�������B
	/// </summary>
	/// <returns>����ꂽ���̃X�g���[�����g�̃|�C���^�B�����Ɏ��s�����ꍇNULL�B</returns>
	virtual pty_stream_buf* close()
	{
		bool status = true;

		if(this->is_open())
		{
			// �v���Z�X�������I������
			if(! ::TerminateProcess(this->process.hProcess, 0))
			{
				// �����I���Ɏ��s
				DWORD code = ::GetLastError();
				status = false;
			}

			// �s�v�ɂȂ����n���h�����폜����
			// �p�C�v�̃n���h��
			::CloseHandle(this->pipeOut);
			::CloseHandle(this->pipeIn);

			// �v���Z�X�̃n���h��
			::CloseHandle(this->process.hProcess);
			// we need this?
			::CloseHandle(this->process.hThread);

			// �v���Z�X���I�u�W�F�N�g���N���A
			::ZeroMemory(&(this->process), sizeof(PROCESS_INFORMATION));
		}

		return (status ? this : 0);
	}

	/// <summary>
	/// ���s����R�}���h�ƈ������w�肵�āA�X�g���[�����J���B
	/// </summary>
	/// <param name="command">���s����R�}���h�t�@�C���p�X�B</param>
	/// <param name="argc">�R�}���h�����̐��B</param>
	/// <param name="argv">�R�}���h������z��B</param>
	/// <returns>�J���ꂽ���̃X�g���[�����g�̃|�C���^�B�����Ɏ��s�����ꍇNULL�B</returns>
	virtual pty_stream_buf* open(char* command, int argc, char** argv)
	{
		BOOL status = TRUE;

		//
		// �v���Z�X�Ƃ̓��o�͂��s���p�C�v���쐬�B
		//
		// �v���Z�X������A�N�Z�X����p�C�v
		HANDLE pipeInChild;
		HANDLE pipeOutChild;

		// �p�C�v�ɑ΂���A�N�Z�X����\����
		SECURITY_ATTRIBUTES sa;

		sa.nLength = sizeof(SECURITY_ATTRIBUTES);
		sa.lpSecurityDescriptor = 0;

		// �p���\(TRUE)���w�肵�Ȃ��ƁA���������v���Z�X������A�N�Z�X�ł��Ȃ�
		sa.bInheritHandle = TRUE;

		// �p�C�v���쐬
		// �����́A�ǂݎ�葤�n���h���A�������ݑ��n���h���A�̏�
		status = ::CreatePipe(&pipeInChild, &(this->pipeOut), &sa, 0)
			&& ::CreatePipe(&(this->pipeIn), &pipeOutChild, &sa, 0);

		if(status)
		{
			//
			// �쐬�����p�C�v���w�肵�āA�v���Z�X���J�n�B
			//
			// �v���Z�X�J�n���I�u�W�F�N�g
			STARTUPINFO si;
			ZeroMemory(&si, sizeof(STARTUPINFO));

			// �\���̃T�C�Y�̐ݒ�͕K�{
			si.cb = sizeof(STARTUPINFO);

			// �W�����o�͂��w�肵�āA�v���Z�X�����s����ݒ�
			si.dwFlags = STARTF_USESTDHANDLES;
			si.hStdOutput = pipeOutChild;
			si.hStdInput = pipeInChild;
			si.hStdError = pipeOutChild;

			// �R�}���h���C���������A��
			char* commandLine = 0;

			this->prepareCommandLine(command, argc, argv, &commandLine);

			// �v���Z�X�J�n
			status = ::CreateProcess(
				0,
				commandLine,      // �{���̌^��LPTSTR
				0,
				0,
				TRUE,             // �n���h���̌p�����\�ɂ���
				CREATE_NO_WINDOW, // �R���\�[���E�B���h�E��\�����Ȃ�
				0,
				0,
				&si,
				&(this->process)
				);

			// �R�}���h���C��������p�̃����������
			delete[] commandLine;
		}

		// �ȍ~�̓v���Z�X������A�N�Z�X����p�C�v�̃n���h���͕s�v�Ȃ��ߕ���
		::CloseHandle(pipeInChild);
		::CloseHandle(pipeOutChild);

		if(status)
		{
			return this;
		}
		else
		{
			// �v���Z�X�̊J�n�Ɏ��s
			// �p�C�v�n���h��������
			::CloseHandle(this->pipeOut);
			::CloseHandle(this->pipeIn);

			return 0;
		}
	}

protected:
	/// <summary>
	/// �o�̓o�b�t�@�̃t���b�V�����ɌĂ΂��B
	/// </summary>
	/// <returns>�����ɐ��������ꍇ0�B���s�����ꍇ�A����ȊO�̒l���Ԃ����B</returns>
	virtual int sync()
	{
		// �p�C�v�Ƀo�b�t�@�����O����Ă���f�[�^���t���b�V��
		::FlushFileBuffers(this->pipeOut);

		return 0;
	}

	/// <summary>
	/// �f�[�^���������݁A�������݈ʒu����i�߂�B
	/// </summary>
	/// <param name="character">�������܂��f�[�^�B</param>
	/// <returns>�o�b�t�@�ɏ������񂾃f�[�^�B�����Ɏ��s�����ꍇ�AEOF���Ԃ����B</returns>
	virtual int overflow(int character = EOF)
	{
		// �o�̓p�C�v�ɑ΂��ăf�[�^����������
		DWORD bytesWritten = 0;

		// ���g���G���f�B�A����O��Ƃ���1�o�C�g�ڂ��o��
		if(! ::WriteFile(this->pipeOut, (char*)(&character), 1, &bytesWritten, 0))
		{
			// �������݂Ɏ��s
			return EOF;
		}

		return character;
	}

	/// <summary>
	/// �f�[�^��ǂݎ��A�ǂݍ��݈ʒu����i�߂�B
	/// </summary>
	/// <remarks>
	/// �o�b�t�@����̃f�[�^�ǂݎ�莞�ɌĂ΂��B
	/// </remarks>
	/// <returns>�ǂݎ��ꂽ�f�[�^�B�I�[�ɒB���Ă���ꍇ�AEOF���Ԃ����B</returns>
	virtual int uflow()
	{
		// �o�b�t�@�Ɋi�[����Ă���f�[�^�����݂���ꍇ�A���̃f�[�^��Ԃ�
		if(this->buffered)
		{
			this->buffered = false;

			return this->buffer;
		}

		// ���̓p�C�v����f�[�^��ǂݍ���
		char data = 0;
		DWORD bytesRead = 0;

		if(! ::ReadFile(this->pipeIn, &data, 1, &bytesRead, 0))
		{
			// �ǂݍ��݂Ɏ��s
			return EOF;
		}

		if(bytesRead == 0)
		{
			// �I�[�ɒB���Ă���
			return EOF;
		}

		return data;
	}

	/// <summary>
	/// �o�b�t�@����ǂݎ��ꂽ�f�[�^���o�b�t�@�ɖ߂��B
	/// </summary>
	/// <param name="character">�߂����f�[�^�B</param>
	/// <returns>�o�b�t�@�ɖ߂����f�[�^�B�����Ɏ��s�����ꍇ�AEOF���Ԃ����B</returns>
	virtual int pbackfail(int character = EOF)
	{
		// �f�[�^���o�b�t�@�Ɋi�[
		this->buffered = true;
		this->buffer = character;

		return character;
	}

	/// <summary>
	/// �f�[�^��ǂݎ��A���̃f�[�^���o�b�t�@�ɖ߂��ēǂݍ��݈ʒu��i�߂Ȃ��B
	/// </summary>
	/// <returns>�ǂݎ��ꂽ�f�[�^�B�����Ɏ��s�����ꍇ�AEOF���Ԃ����B</returns>
	virtual int underflow()
	{
		return this->pbackfail(this->uflow());
	}

private:
	static const size_t DEFAULT_BUFSIZE = 4096;

	/// <summary>
	/// �R�}���h�ƃR�}���h������A��������������쐬����B
	/// </summary>
	/// <remarks>
	/// �R�}���h�t�@�C���p�X�͗��p�����Aargv�̊e��������󔒂ŘA�����č쐬����B
	/// </remarks>
	/// <param name="command">�R�}���h�t�@�C���p�X�B</param>
	/// <param name="argc">�R�}���h�����̐��B</param>
	/// <param name="argv">�R�}���h������z��B</param>
	/// <param name="buf">�A��������������i�[����o�b�t�@���w���|�C���^�B</param>
	void prepareCommandLine(char* command, int argc, char** argv, char** buf) const
	{
		int length = 0;//strlen(command);

		// �S�̂̒��������߂�B
		int commandLength = length;

		for(int i=0; i<argc; i++)
		{
			// �󔒕��� + �����̕�����B
			commandLength += 1 + strlen(*(argv + i));
		}

		// �I�[�����B
		commandLength ++;

		// �o�b�t�@���m�ہB
		*buf = new char[commandLength];
		char* wk = *buf;

		// command�͗��p���Ȃ��B
		//memcpy(wk, command, length);
		//wk += length;

		// �ŏ��̕�����B
		length = strlen(*argv);
		memcpy(wk, *argv, length);
		wk += length;

		for(int i=1; i<argc; i++)
		{
			// �󔒂ň�����ڑ�����
			*(wk++) = ' ';

			length = strlen(*(argv + i));

			memcpy(wk, *(argv + i), length);
			wk += length;
		}

		*(wk++) = 0;
	}

	int buffer;
	bool buffered;

	/// <summary>�X�g���[���̊֘A�t������v���Z�X�̏��I�u�W�F�N�g�B</summary>
	PROCESS_INFORMATION process;

	/// <summary>�v���Z�X�ւ̏������݃p�C�v�n���h���B</summary>
	HANDLE pipeOut;
	/// <summary>�v���Z�X����̓ǂݎ��p�C�v�n���h���B</summary>
	HANDLE pipeIn;
};

#ifndef PTY_STREAM_JOB
#define PTY_STREAM_JOB TEXT("PTY-STREAM-JOB")
#endif

/// <summary>
/// �v���Z�X�ԒʐM�̃X�g���[�������N���X�B
/// </summary>
class pty_stream : public std::iostream
{
public:
	pty_stream(void) : std::iostream(0)
	{
		this->init(&(this->buf));
	}

	pty_stream( char* command_, int argc_, char** argv_ ) : std::iostream(0)
	{
		this->init(&(this->buf));
		this->open( command_, argc_, argv_ );
	}

	/// <summary>
	/// ���s����R�}���h�ƈ������w�肵�āA�X�g���[�����J���B
	/// </summary>
	/// <param name="command">���s����R�}���h�t�@�C���p�X�B</param>
	/// <param name="argc">�R�}���h�����̐��B</param>
	/// <param name="argv">�R�}���h������z��B</param>
	void open(char* command, int argc, char** argv)
	{
		if(this->buf.open(command, argc, argv))
		{
			// ���݂���΃W���u�I�u�W�F�N�g�擾�B
			this->hJob = OpenJobObject(JOB_OBJECT_ASSIGN_PROCESS, false, PTY_STREAM_JOB);

			if(this->hJob == 0)
			{
				// ���݂��Ȃ��ꍇ�A�W���u�I�u�W�F�N�g�쐬�B
				HANDLE cJob = CreateJobObject(NULL, PTY_STREAM_JOB);

				JOBOBJECT_EXTENDED_LIMIT_INFORMATION info;
				ZeroMemory(&info, sizeof(JOBOBJECT_EXTENDED_LIMIT_INFORMATION));

				info.BasicLimitInformation.LimitFlags = JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE;

				SetInformationJobObject(cJob, JOBOBJECTINFOCLASS::JobObjectExtendedLimitInformation, &info, sizeof(JOBOBJECT_EXTENDED_LIMIT_INFORMATION));

				// ���߂ăn���h���擾�B
				this->hJob = OpenJobObject(JOB_OBJECT_ASSIGN_PROCESS, false, PTY_STREAM_JOB);

				// �쐬�ɗ��p�����n���h���͕���B
				CloseHandle(cJob);
			}

			// �v���Z�X�ɃW���u���֘A�t����B
			AssignProcessToJobObject(this->hJob, this->buf.getProcess());
		}
	}

	/// <summary>
	/// �v���Z�X���I�����ăX�g���[�������B
	/// </summary>
	/// <returns>����ꂽ���̃X�g���[�����g�̃|�C���^�B�����Ɏ��s�����ꍇNULL�B</returns>
	void close()
	{
		this->buf.close();

		CloseHandle(this->hJob);
	}

	int get_fd() const { return this->buf.get_fd(); }
	int get_pid() const { return this->buf.get_pid(); }

	/// <summary>
	/// �s��ǂݎ��A�s���Ɏc���ꂽCR����菜���B
	/// </summary>
	/// <param name="in">���̓X�g���[���B</param>
	/// <param name="line">�s���i�[���镶����B</param>
	/// <returns>�s��ǂݎ�������̓X�g���[���B</returns>
	static pty_stream& getline(pty_stream& in, std::string& line)
	{
		std::getline(in, line);

		if(!line.empty())
		{
			std::string::iterator it = line.end() - 1;

			if(*it == '\r')
			{
				line.erase(it);
			}
		}

		return in;
	}

private:
	pty_stream_buf buf;

	HANDLE hJob;
};

typedef pty_stream process_istream;
typedef pty_stream process_ostream;

#else

class process_stream_buf : public std::streambuf {
public:
  typedef size_t size_type;
  typedef char char_type;
  static const size_type DEFAULT_BUFFER_SIZE = 4096;

private:
  size_type buffer_size;
  char_type* buffer;

  int fd;
  int pid;
  //char* command;
  //int argc;
  //char** argv;
  bool read_mode;
  bool is_eof;

public:
  process_stream_buf( size_type s = DEFAULT_BUFFER_SIZE ) {
    buffer_size = s;
    buffer = new char_type[ buffer_size ];
  }
  virtual ~process_stream_buf() {
    close();
    delete [] buffer;
  }

  int get_fd() const { return fd; }
  int get_pid() const { return pid; }

  virtual bool is_open() const {
    return pid > 0;
  }
  //virtual bool eof() const { return is_eof; }

  virtual process_stream_buf* close() {
    if ( pid > 0 ) {
      if ( ::close( fd ) < 0 || waitpid( pid, NULL, 0 ) < 0 ) {
        RUNERR( "Cannot close process stream" );
        pid = 0;
        return NULL;
      }
    }
    pid = 0;
    return this;
  }

  virtual process_stream_buf* open(char* command_, int, char** argv_, bool read_mode_) {
    //command =  command_;
    //argc = argc_;
    //argv = argv_;
    pid = 0;
    is_eof = false;
    read_mode = read_mode_;
//     read_mode = false;
//     if ( strcmp( option_, "r" ) == 0 ) {
//       read_mode = true;
//     } else if ( strcmp( option_, "w" ) == 0 ) {
//       read_mode = false;
//     } else {
//       RUNERR( "Invalid open mode for process stream: " << option_ );
//       return NULL;
//     }
    int pipe_fd[ 2 ];
    if ( pipe( pipe_fd ) < 0 ) {
      RUNERR( "Cannot create a new pipe for process stream" );
      return NULL;
    }
#ifdef PROFILE    
    profiler::StopSignals();
#endif
    pid = fork();
    if ( pid < 0 ) {
      RUNERR( "Cannot fork a new process" );
      pid = 0;
#ifdef PROFILE    
      profiler::StartSignals();
#endif
      return NULL;
    }
    if ( pid == 0 ) {
      if ( read_mode ) {
        dup2( pipe_fd[ 1 ], 1 );
        // stderr is ignored
        //dup2( pipe_fd[ 1 ], 2 );
      } else {
        dup2( pipe_fd[ 0 ], 0 );
      }
      ::close( pipe_fd[ 0 ] );
      ::close( pipe_fd[ 1 ] );
      execvp( command_, argv_ );
      RUNERR( "Execution of command failed: " << command_ );
      exit( 1 );
    }
#ifdef PROFILE    
    profiler::StartSignals();
#endif
    if ( read_mode ) {
      fd = pipe_fd[ 0 ];
      ::close( pipe_fd[ 1 ] );
    } else {
      fd = pipe_fd[ 1 ];
      ::close( pipe_fd[ 0 ] );
    }
    return this;
  }

  int sync() {
    if ( ! read_mode ) {
      char_type* buffer_ptr = buffer;
      while ( buffer_ptr < pptr() ) {
        int count = write( fd, buffer_ptr, pptr() - buffer_ptr );
        if ( count <= 0 ) return -1;
        buffer_ptr += count;
      }
      setp( buffer, buffer + buffer_size );
    }
    return 0;
  }

  int underflow() {
    if ( ! read_mode ) return EOF;
    int count = read(fd, buffer, buffer_size);
    setg( buffer, buffer, buffer + count );
    return count <= 0 ? EOF : *buffer;
  }

  int overflow( int c = EOF ) {
    if ( read_mode ) return EOF;
    sync();
    if ( c == EOF ) return EOF;
    *buffer = c;
    pbump( 1 );
    return c;
  }
};

//////////////////////////////////////////////////////////////////////
////
//// streambuf for pty communication
////
//////////////////////////////////////////////////////////////////////

class pty_stream_buf : public std::streambuf {
public:
  typedef size_t size_type;
  typedef char char_type;
  static const size_type DEFAULT_BUFFER_SIZE = 4096;

private:
  size_type buffer_size;
  char_type* in_buffer;
  char_type* out_buffer;

  int fd;
  int pid;
  //char* command;
  //int argc;
  //char** argv;
  bool is_eof;

public:
  pty_stream_buf( size_type s = DEFAULT_BUFFER_SIZE ) {
    buffer_size = s;
    in_buffer = new char_type[ buffer_size ];
    out_buffer = new char_type[ buffer_size ];
  }
  virtual ~pty_stream_buf() {
    close();
    delete [] in_buffer;
    delete [] out_buffer;
  }

  int get_fd() const { return fd; }
  int get_pid() const { return pid; }

  virtual bool is_open() const {
    return pid > 0;
  }
  //virtual bool eof() const { return is_eof; }

  virtual pty_stream_buf* close() {
    if ( pid > 0 ) {
      if ( ::close( fd ) < 0 || waitpid( pid, NULL, 0 ) < 0 ) {
        RUNERR( "Cannot close pty stream" );
        pid = 0;
        return NULL;
      }
    }
    is_eof = true;
    pid = 0;
    return this;
  }

  virtual pty_stream_buf* open(char* command_, int, char** argv_ ) {
    //command = command_;
    //argc = argc_;
    //argv = argv_;
    pid = 0;
    is_eof = false;
#if ( ( defined( HAVE_LIBUTIL ) && defined( HAVE_OPENPTY ) ) || defined( HAVE_GRANTPT ) )
    int slave_fd = 0;
#if ( defined( HAVE_LIBUTIL ) && defined( HAVE_OPENPTY ) )
    if ( openpty( &fd, &slave_fd, NULL, NULL, NULL ) < 0 ) {
      RUNERR( "Cannot open pseudo tty" );
      return NULL;
    }
#else // HAVE_OPENPTY
#ifdef IS_GXX
    fd = ::open( "/dev/ptmx", O_RDWR | O_NOCTTY );
#else
    fd = ::open( "/dev/ptc", O_RDWR | O_NOCTTY );
#endif
    if ( fd < 0 ) {
      RUNERR( "Cannot open pseudo tty" );
      return NULL;
    }
    if ( grantpt( fd ) < 0 || unlockpt( fd ) < 0 ) {
      RUNERR( "Cannot initialize pseudo tty" );
      return NULL;
    }
    char* slave_name = ptsname( fd );
    if ( slave_name == NULL ) {
      RUNERR( "Cannot get the name of a slave tty" );
      return NULL;
    }
    slave_fd = ::open( slave_name, O_RDWR | O_NOCTTY );
    if ( slave_fd < 0 ) {
      RUNERR( "Cannot open a slave tty" );
      return NULL;
    }
#ifdef I_PUSH
#ifdef IS_GXX
    ioctl( slave_fd, I_PUSH, "ptem" );
    ioctl( slave_fd, I_PUSH, "ldterm" );
    ioctl( slave_fd, I_PUSH, "ttcompat" );
#endif
#endif // I_PUSH
#endif // HAVE_OPENPTY
    struct termios stermios;
    if ( tcgetattr( slave_fd, &stermios ) < 0 ) {
      RUNERR( "Cannot get terminal attributes" );
      return NULL;
    }
    stermios.c_lflag &= ~( ECHO | ECHOE | ECHOK | ECHONL );
    //stermios.c_lflag |= ICANON;  // this will cause deadlock when more than 4096 bytes of data is input
    stermios.c_lflag &= ~ICANON;
    stermios.c_oflag &= ~( ONLCR );
    if ( tcsetattr( slave_fd, TCSANOW, &stermios ) < 0 ) {
      RUNERR( "Cannot set terminal attributes" );
      return NULL;
    }
#ifdef PROFILE    
    profiler::StopSignals();
#endif
    pid = fork();
    if ( pid < 0 ) {
      RUNERR( "Cannot fork a new process" );
      pid = 0;
#ifdef PROFILE    
      profiler::StartSignals();
#endif
      return NULL;
    }
    if ( pid == 0 ) {
      dup2( slave_fd, 0 );
      dup2( slave_fd, 1 );
      // stderr is ignored
      //dup2( slave_fd, 2 );
      ::close( fd );
      ::close( slave_fd );
      execvp( command_, argv_ );
      RUNERR( "Execution of command failed: " << command_ );
      exit( 1 );
    }
#ifdef PROFILE    
    profiler::StartSignals();
#endif
    ::close( slave_fd );
    return this;
#else // HAVE_OPENPTY || HAVE_GRANTPT
    fd = -1;
    RUNERR( "This executable does not support pseudo-tty stream" );
    return NULL;
#endif // HAVE_OPENPTY || HAVE_GRANTPT
  }

  int sync() {
    char_type* buffer_ptr = out_buffer;
    //std::cerr << "sync: " << pptr() - buffer_ptr << std::endl;
    while ( buffer_ptr < pptr() ) {
      int count = write( fd, buffer_ptr, pptr() - buffer_ptr );
      //std::cerr << "count: " << count << std::endl;
      if ( count <= 0 ) return -1;
      buffer_ptr += count;
    }
    setp( out_buffer, out_buffer + buffer_size );
    return 0;
  }

  int underflow() {
    int count = read(fd, in_buffer, buffer_size);
    setg( in_buffer, in_buffer, in_buffer + count );
    return count <= 0 ? EOF : *in_buffer;
  }

  int overflow( int c = EOF ) {
    sync();
    if ( c == EOF ) return EOF;
    *out_buffer = c;
    pbump( 1 );
    return c;
  }
};

//////////////////////////////////////////////////////////////////////
////
////  iostream interface with process stream
////
//////////////////////////////////////////////////////////////////////

class process_istream : public std::istream {
private:
  process_stream_buf bf_buf;

public:
  process_istream() : std::istream( NULL ), bf_buf() {
    init( &bf_buf );
  }
  explicit process_istream( char* command_, int argc_, char** argv_ )
    : std::istream( NULL ), bf_buf() {
    init( &bf_buf );
    open( command_, argc_, argv_ );
  }
  virtual ~process_istream() {
  }

public:
  int get_fd() const { return bf_buf.get_fd(); }
  int get_pid() const { return bf_buf.get_pid(); }

  void open( char* command_, int argc_, char** argv_ ) {
    if ( ! bf_buf.open( command_, argc_, argv_, true ) ) {
      setstate( std::ios::failbit );
    }
  }
  void close() {
    if ( ! bf_buf.close() ) {
      setstate( std::ios::failbit );
    }
  }
};

class process_ostream : public std::ostream {
private:
  process_stream_buf bf_buf;

public:
  process_ostream() : std::ostream( NULL ), bf_buf() {
    init( &bf_buf );
  }
  explicit process_ostream( char* command_, int argc_, char** argv_ )
    : std::ostream( NULL ), bf_buf() {
    init( &bf_buf );
    open( command_, argc_, argv_ );
  }
  virtual ~process_ostream() {
  }

public:
  int get_fd() const { return bf_buf.get_fd(); }
  int get_pid() const { return bf_buf.get_pid(); }

  void open( char* command_, int argc_, char** argv_ ) {
    if ( ! bf_buf.open( command_, argc_, argv_, false ) ) {
      setstate( std::ios::failbit );
    }
  }
  void close() {
    if ( ! bf_buf.close() ) {
      setstate( std::ios::failbit );
    }
  }
};

//////////////////////////////////////////////////////////////////////
////
////  iostream interface with pty stream
////
//////////////////////////////////////////////////////////////////////

class pty_stream : public std::iostream {
private:
  pty_stream_buf bf_buf;

public:
  pty_stream() : std::iostream( NULL ), bf_buf() {
    init( &bf_buf );
  }
  pty_stream( char* command_, int argc_, char** argv_ )
    : std::iostream( NULL ), bf_buf() {
    init( &bf_buf );
    open( command_, argc_, argv_ );
  }
  virtual ~pty_stream() {
  }

public:
  int get_fd() const { return bf_buf.get_fd(); }
  int get_pid() const { return bf_buf.get_pid(); }

  void open( char* command_, int argc_, char** argv_ ) {
    if ( ! bf_buf.open( command_, argc_, argv_ ) ) {
      setstate( std::ios::failbit );
    }
  }
  void close() {
    if ( ! bf_buf.close() ) {
      setstate( std::ios::failbit );
    }
  }
};

#endif

} // namespace lilfes

#endif // __procstream_h
