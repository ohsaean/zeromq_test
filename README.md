**ZeroMQ, Boost with VisualStudio 2015**

    ZMQ_HOME:        libzmq 소스 위치
    ZMQ_CPP_HEADERS: cppzmq 소스 위치
    ZMQ_LIBS:        libzmq 빌드 결과 위치 (bin 폴더)
    ZMQ_LIBSODIUM:   libsodium (중요: libsodium 소스는 libzmq-root 바로 밑에 위치 시켜야함)
    ZMQ_ZGUIDE:      zguide 소스 위치
    BOOST_HOME       boost 소스 위치
    BOOST_LIBS       boost 라이브러리 빌드 위치


* 시스템 - 환경변수 - 유저 환경 변수에서 위 변수를 설정해야 함


**프로젝트 속성 - 구성 속성 - C/C++ - 일반 - 추가 포함 디렉터리**

* $(ZMQ_HOME)\include
* $(ZMQ_ZGUIDE)\examples\C++
* $(ZMQ_CPP_HEADERS)


**프로젝트 속성 - 구성 속성 - 링커 - 일반 - 추가 라이브러리 디렉터리**

* $(ZMQ_LIBS)\$(Platform)\$(Configuration)\$(DefaultPlatformToolset)\dynamic


**프로젝트 속성 - 구성 속성 - 링커 - 입력 - 추가 종속성**

* libzmq.lib 추가


**프로젝트 속성 - 구성 속성 - 빌드 이벤트 - 빌드 후 이벤트**

* copy $(ZMQ_LIBS)\$(Platform)\$(Configuration)\$(DefaultPlatformToolset)\dynamic\libzmq.dll $(OutputPath)
* copy $(ZMQ_LIBSODIUM)\$(Platform)\$(Configuration)\$(DefaultPlatformToolset)\dynamic\libsodium.dll $(OutputPath)


**프로젝트 속성 - 구성 속성 - VC++ 디렉터리 - 포함 디렉터리**

* $(BOOST_HOME) 추가


**프로젝트 속성 - 구성 속성 - VC++ 디렉터리 - 라이브러리 디렉터리**

* $(BOOST_LIBS)\$(Platform)\lib 추가