/*
*
*   - Author: jrius (vk.com/s.fridom & t.me/dcapybarov & github.com/jr1us) -
*   - Include: Long Message - 
*   - ������ ���������� �� ������ ����������� 3.10.8 -
*
*   - ������ ������������� ��������� �������:
*
*       * SendClientMessage_Long(playerid, color, const input[])
*           - �������� ���������� �������� � ��������� �������� ��� �� ������ ���� ����� ��������� 144 �������;
*           - ����� �������� ����: \n & \t (\n ��������� ������ | \t ��������� 4 �������)

*       * SendClientMessageToAll_Long(color, const input[])
*           - �������� ���������� �������� � ��������� �������� ��� �� ������ ���� ����� ��������� 144 �������;
*           - ����� �������� ����: \n & \t (\n ��������� ������ | \t ��������� 4 �������)
*
*       - ���������� ���������� � ������ ����:  #include <long-message>
*       - ������������ ������� ����� �� �������: SendClientMessage(playerid, color, ...) ��� SendClientMessageToAll(color, ...)
*       - ������� ����������� ������.
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