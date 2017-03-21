**ZeroMQ with VisualStudio 2015**

    ZMQ_HOME:        sources from zeromq/libzmq
    ZMQ_CPP_HEADERS: sources from zeromq/cppzmq
    ZMQ_LIBS:        binaries compiled from ZMQ_HOME directory
    ZMQ_LIBSODIUM:   sources from jedisct1/libsodium (IMPORTANT: libsodium must go inside the libzmq-root directory so the ZMQ-lib can be compiled with libsodium support)
    ZMQ_ZGUIDE:      sources from booksbyus/zguide 


**프로젝트 속성 - 구성 속성 - C/C++ - 일반 - 추가 포함 디렉터리**

$(ZMQ_HOME)\include
$(ZMQ_ZGUIDE)\examples\C++
$(ZMQ_CPP_HEADERS)

**링커 - 일반 - 추가 라이브러리 디렉터리**
$(ZMQ_LIBS)\$(Platform)\$(Configuration)\$(DefaultPlatformToolset)\dynamic

**링커 - 입력 - 추가 종속성**
libzmq.lib 추가

**프로젝트 속성 - 구 속성 - 빌드 이벤트 - 빌드 후 이벤트**
copy $(ZMQ_LIBS)\$(Platform)\$(Configuration)\$(DefaultPlatformToolset)\dynamic\libzmq.dll $(OutputPath)
copy $(ZMQ_LIBSODIUM)\$(Platform)\$(Configuration)\$(DefaultPlatformToolset)\dynamic\libsodium.dll $(OutputPath)
