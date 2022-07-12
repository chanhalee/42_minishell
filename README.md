# 42_minishell

**간단한 쉘 만들기**

readline 라이브러리 설치
brew install readline

readline 라이브러리 위치 확인
brew info readline

컴파일
gcc test.c -L/$HOME/.brew/opt/readline/lib -I/$HOME/.brew/opt/readline/include -lreadline

-   참가인원

    -   jeounpar(박정규) - 명령 실행 체계 구현<br>
    -   chanhale(이찬하) - 입력 파싱 및 명령 구조화

-   진행기간

    2022-07-07 ~

-   구현 완료
    입력 프롬프트 생성
    signal 처리 (SIGINT, SIGTERM, SIGQUIT)
