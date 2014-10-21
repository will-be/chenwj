/** 
 * @file HelloWorld.c
 * @brief 
 * @author Chenwj
 * @version 0.1
 * @date 2014-10-21
 */

#include <curses.h>
#include <stdlib.h>
#include <stdio.h>

void initial ( void )
{
    initscr ( );
    nonl ( );
    noecho ( );
    intrflush ( stdscr, FALSE );
    keypad ( stdscr, FALSE );
    refresh ( );
}

void attr_test ( void )
{
    attrset(A_NORMAL); /* 先将属性设定为正常模式 */ 

    attron(A_UNDERLINE); /* 加底线 */
    mvaddstr(9,10,"Under line"); /* 加底线输出一串字元 */
    attroff(A_UNDERLINE); /* 关闭加底线模式, 恢复正常模式 */

    attron(A_REVERSE); /* 开启反白模式 */
    mvaddstr(10,10,"Reverse"); /* 输出一串反白字元 */
    attroff(A_REVERSE); /* 关闭反白模式, 恢复正常模式 */

    attron(A_BLINK); /* 开启闪烁模式 */
    mvaddstr(11,10,"Blink"); /* 输出一串闪烁字元 */
    attroff(A_BLINK); /* 关闭闪烁模式, 恢复正常模式 */

    attron(A_BOLD); /* 开启高亮度模式 */
    mvaddstr(12,10,"Bold"); /* 输出一串高亮度字元 */
    attroff(A_BOLD); /* 关闭高亮度模式, 恢复正常模式 */
}

void io_str_test ( void )
{
    /* printw ( "Helloworld !" );                                                      // ok */
    mvaddstr ( 1, 20, "Helloworld !" );                                            // ok, 坐标不能超出屏幕范围，否则看不见 
    addch ( '#' );                                                                  // ok
    mvaddstr ( 2, 10, "XyZ" );                                                     // ok
    echochar ( '@' );                                                               // ok

    int ch = getch ( );
    mvprintw ( 5, 0, "getch() = %d", ch );                                         // ok

    char string1[80];   /* 请注意! 不可宣告为 char *string1; */
    char string2[80];

    echo();             /* 开启 echo 模式, 使输入立刻显示在萤幕上 */
    ch=getch();
    getstr(string1);
    scanw("%s",string2);

    attron ( A_UNDERLINE );
    mvprintw(10,10,"String1=%s",string1);
    attroff ( A_UNDERLINE );
    attron ( A_REVERSE );
    mvprintw(11,10,"String2=%s",string2);
    attroff ( A_REVERSE );


}

void hello_world ( void )
{
    initial ( );

    box ( stdscr, '|', '-' );
    move ( LINES / 2, COLS / 2 );
    waddstr ( stdscr, "HelloWorld" );
    getch ( );
    endwin ( );
}

int main ( void )
{
    hello_world ( );
    return 0;
}
