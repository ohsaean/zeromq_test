**ZeroMQ with VisualStudio 2015**

    ZMQ_HOME:        libzmq 소스 위치
    ZMQ_CPP_HEADERS: cppzmq 소스 위치
    ZMQ_LIBS:        libzmq 빌드 결과 위치 (bin 폴더)
    ZMQ_LIBSODIUM:   libsodium (중요: libsodium 소스는 libzmq-root 바로 밑에 위치 시켜야함)
    ZMQ_ZGUIDE:      zguide 소스 위치


**프로젝트 속성 - 구성 속성 - C/C++ - 일반 - 추가 포함 디렉터리**

* $(ZMQ_HOME)\include
* $(ZMQ_ZGUIDE)\examples\C++
* $(ZMQ_CPP_HEADERS)


**링커 - 일반 - 추가 라이브러리 디렉터리**

* $(ZMQ_LIBS)\$(Platform)\$(Configuration)\$(DefaultPlatformToolset)\dynamic


**링커 - 입력 - 추가 종속성**

* libzmq.lib 추가


**프로젝트 속성 - 구 속성 - 빌드 이벤트 - 빌드 후 이벤트**

* copy $(ZMQ_LIBS)\$(Platform)\$(Configuration)\$(DefaultPlatformToolset)\dynamic\libzmq.dll $(OutputPath)
* copy $(ZMQ_LIBSODIUM)\$(Platform)\$(Configuration)\$(DefaultPlatformToolset)\dynamic\libsodium.dll $(OutputPath)
