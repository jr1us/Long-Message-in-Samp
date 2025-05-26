/*
*
*   - Author: jrius (vk.com/s.fridom & t.me/dcapybarov & github.com/jr1us) -
*   - Include: Long Message - 
*   - Модуль разработан на версии компилятора 3.10.8 -
*
*   - Модуль предоставляет следующие функции:
*
*       * SendClientMessage_Long(playerid, color, const input[])
*           - Повышает количество символов в сообщение разделяя его на другие если длина превышает 144 символа;
*           - Также доступны теги: \n & \t (\n Переносит строку | \t Добавляет 4 пробела)

*       * SendClientMessageToAll_Long(color, const input[])
*           - Повышает количество символов в сообщение разделяя его на другие если длина превышает 144 символа;
*           - Также доступны теги: \n & \t (\n Переносит строку | \t Добавляет 4 пробела)
*
*       - Подключать желательно в начале мода:  #include <long-message>
*       - Использовать функции можно по дефолту: SendClientMessage(playerid, color, ...) или SendClientMessageToAll(color, ...)
*       - Функции перехвачены хуками.
*/

stock SendClientMessage_Long(playerid, color, const input[])
{
    new line[144], j, c;

    for (new i = 0; (c = input[i]); i++)
    {
        if (c == '\n' || j == sizeof(line) - 1)
        {
            line[j] = '\0';
            j = 0;
            
            SendClientMessage(playerid, color, line);
        }
        
        line[j++] = (c == '\t') ? (' ') : (c);

        if (c == '\t' && j < sizeof(line) - 3) 
        {
            line[j++] = ' ';
            line[j++] = ' ';
            line[j++] = ' ';
            line[j++] = ' ';
        }
    }

    if (j)
    {
        line[j] = '\0';
        SendClientMessage(playerid, color, line);
    }
}

#if defined _ALS_SendClientMessage
    #undef SendClientMessage
#else
    #define _ALS_SendClientMessage
#endif
#define SendClientMessage SendClientMessage_Long

stock SendClientMessageToAll_Long(color, const input[])
{
    new line[144], j, c;

    for (new i = 0; (c = input[i]); i++)
    {
        if (c == '\n' || j == sizeof(line) - 1)
        {
            line[j] = '\0';
            j = 0;

            SendClientMessageToAll(color, line);
        }
        
        line[j++] = (c == '\t') ? (' ') : (c);
        if (c == '\t' && j < sizeof(line) - 3) 
        {
            line[j++] = ' ';
            line[j++] = ' ';
            line[j++] = ' ';
            line[j++] = ' ';
        }
    }

    if (j)
    {
        line[j] = '\0';
        SendClientMessageToAll(color, line);
    }
}

#if defined _ALS_SendClientMessageToAll
    #undef SendClientMessageToAll
#else
    #define _ALS_SendClientMessageToAll
#endif
#define SendClientMessageToAll SendClientMessageToAll_Long