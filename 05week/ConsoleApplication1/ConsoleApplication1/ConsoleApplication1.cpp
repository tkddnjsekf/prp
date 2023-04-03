#ifndef DEBUG
#endif // !DEBUG
#include <iostream>
#include <conio.h>
#include <Windows.h>

//gamestate == 0번
int title_screen()
{
    std::cout << "*******************************" ;
    std::cout << "*                             *" << std::endl;
    std::cout << "*                             *" << std::endl;
    std::cout << "*           지렁이 게임       *" << std::endl;
    std::cout << "*          (Snake bite)       *" << std::endl;
#ifndef DEBUG //디버그모드 띄울려면  1,2번도 해야함 (컴파일 옵션)
    std::cout << "*        - 디버그 모드 -      *" << std::endl;
#else //이거 하면 줄 안띠움
#endif // !DEBUGstd::cout << "*                             *" << std::endl;
    std::cout << "*        1.  게임 시작        *" << std::endl;
    std::cout << "*        2.  게임 설명        *" << std::endl;
    std::cout << "*        3.  게임 랭킹        *" << std::endl;
    std::cout << "*        4.  게임 종료 (esc)  *" << std::endl;
    std::cout << "*                             *" << std::endl;
    std::cout << "*                             *" << std::endl;
    std::cout << "*******************************" << std::endl;

    return 0;
}

void gotaxy(int x, int y) // 맵 이걸로 찍음 = 과제
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}
//gamestate == 1번
int play_screen(int stage_width, int stage_height)
//width height 입력받으면 그거만큼 별 찍어서 맵 만들기
{

}
//gamestate == 2번
int Tip_text() 
{

    std::cout << "*********************************************" << std::endl;
    std::cout << "*  타이틀 화면으로 돌아가시겠습니까? (Y/N)  *" << std::endl;
    std::cout << "*              Y = 1번 / N = 2번            *" << std::endl;
    std::cout << "*********************************************" << std::endl;

    return 0;
}


int main()
{
    int gamestate = 0;
    int is_game_play = 1;
    title_screen();

    char c = _getch();

    while (1)
    {
        char key_input = '0';
        switch (gamestate)
        {
        case 0:
            title_screen();
            key_input = _getch();
            switch (key_input)
            {
            case '1':
                break;
            case '2':
                gamestate = 2;
                break;
            case '3':
                break;
            case '4':
                is_game_play = 0;
            case 27:
                is_game_play = 0;
                break;
            default:
                break;
            }
            break;
        case 2:

            Tip_text();
            key_input = _getch();
            switch (key_input)
            {
            case 'y':
                gamestate = 0;
                break;
            case 'n':
                break;
            default:
                break;

            }
            break;
        }

        return 0;

    }
}