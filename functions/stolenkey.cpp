#include "stolenkey.h"

BOOL CALLBACK DlgStolenKey(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
    case WM_INITDIALOG:
    {
    }
    return TRUE;

    case WM_CLOSE:
    {
        EndDialog(hwndDlg, 0);
    }
    return TRUE;

    case WM_HELP:
    {
        char id[10] = "";
        sprintf(id, "%d", IDS_HELPKEYFUNCTIONS);
        SetEnvironmentVariableA("HELPID", id);
        SetEnvironmentVariableA("HELPTITLE", "Key Functions Help");
        DialogBox(hInst, MAKEINTRESOURCE(DLG_HELP), hwndDlg, DlgHelp);
    }
    return TRUE;

    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {
        case IDC_BTN_DECODE:
        {
            /*
            sprintf(log_msg, "Encrypted KeyBytes (Len: %d, 0x%X):", keylength, keylength);
            AddLogMessage(log, log_msg, false);
            ByteArray2String((unsigned char*)keybytes, log_msg, keylength, 1024);
            AddLogMessage(log, log_msg, false);

            //Decrypt the rest of the key
            CookText(cooked, name);
            unsigned int seed_array = crc32(cooked, strlen(cooked), NewCRC32);
            InitRandomGenerator(seed_array);
            sprintf(log_msg, "NextRandomRange Array (Seed=%.8X):\r\n", seed_array);
            int y;
            for(x = 0, y = 0; x < keylength; x++)
            {
                unsigned char ran = (unsigned char)(NextRandomRange(256) & 0xFF);
                keybytes[x] ^= ran;
                y += sprintf(log_msg + y, "%.2X", ran);
            }
            AddLogMessage(log, log_msg, false);

            AddLogMessage(log, "Decrypted KeyBytes:", false);
            ByteArray2String((unsigned char*)keybytes, log_msg, keylength, 1024);
            AddLogMessage(log, log_msg, false);

            //Assign bytes to their proper locations.
            kb = keybytes;

            if(keystring)
            {
                int keystring_size = 0;
                memcpy(&keystring_size, &kb[keylength - 1], 1); //Safe conversion of the size
                for(x = 0; x < keystring_size; x++)
                    keystring_text[x] = kb[keylength - 2 - x];
                keylength -= keystring_size + 1;
                sprintf(log_msg, "KeyString Bytes (Len: %d, 0x%X):", keystring_size + 1, keystring_size + 1);
                AddLogMessage(log, log_msg, false);
                _strrev(keystring_text);
                ByteArray2String((unsigned char*)keystring_text, log_msg, keystring_size, 1024);
                _strrev(keystring_text);
                sprintf(log_msg, "%s%.2X", log_msg, keystring_size);
                AddLogMessage(log, log_msg, false);
            }

            if(keylength > 14)
            {
                for(x = 0; x < 2; x++)
                {
                    keyotherinfo[4] = keyotherinfo[4] << 8;
                    keyotherinfo[4] |= (unsigned char)kb[0];
                    kb++;
                }
            }
            if(keylength > 12)
            {
                for(x = 0; x < 2; x++)
                {
                    keyotherinfo[3] = keyotherinfo[3] << 8;
                    keyotherinfo[3] |= (unsigned char)kb[0];
                    kb++;
                }
            }
            if(keylength > 10)
            {
                for(x = 0; x < 2; x++)
                {
                    keyotherinfo[2] = keyotherinfo[2] << 8;
                    keyotherinfo[2] |= (unsigned char)kb[0];
                    kb++;
                }
            }
            if(keylength > 8)
            {
                for(x = 0; x < 2; x++)
                {
                    keyotherinfo[1] = keyotherinfo[1] << 8;
                    keyotherinfo[1] |= (unsigned char)kb[0];
                    kb++;
                }
            }
            if(keylength > 6)
            {
                for(x = 0; x < 2; x++)
                {
                    keyotherinfo[0] = keyotherinfo[0] << 8;
                    keyotherinfo[0] |= (unsigned char)kb[0];
                    kb++;
                }
            }
            for(x = 0; x < 2; x++)
            {
                keydatecreated = keydatecreated << 8;
                keydatecreated |= (unsigned char)kb[0];
                kb++;
            }
            for(x = 0; x < 4; x++)
            {
                keytemplateID = keytemplateID << 8;
                keytemplateID |= (unsigned char)kb[0];
                kb++;
            }
             */
        }
        return TRUE;

        case IDC_BTN_ENCODE:
        {
            char keybytes_string[1024] = "";
            unsigned char keybytes[512] = {0};
            char serial[512] = "";
            if(GetDlgItemTextA(hwndDlg, IDC_EDT_DECODED, keybytes_string, 1024))
            {
                int keylength = StringToByteArray(keybytes_string, keybytes, 512);
                strcpy(serial, EncodeShortV3(keybytes, keylength, !!IsDlgButtonChecked(hwndDlg, IDC_CHK_LVL10_ENCODE)));
                SetDlgItemTextA(hwndDlg, IDC_EDT_ENCODED, serial);
                SetFocus(GetDlgItem(hwndDlg, IDC_EDT_ENCODED));
            }
        }
        return TRUE;
        }
    }
    return TRUE;
    }
    return FALSE;
}
