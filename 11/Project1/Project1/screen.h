/* ���� �ʱ�ȭ �Լ� */
int clearBuffer(char* screenBuf, int width, int height);

/* �����ð��� ��� x,y�� ��Ʈ���� ���� �Լ��� ¥�� ��. */
int writeStringToBuffer(const char* string, int x, int y);

/* Ÿ��Ʋ ȭ�� �׸��� ���۶� ���ӿ���, ���Ӽ��� ��� �̷������� ����� ���� ���ϰ���? */
int setTitleToScreenBuffer(char* screenBuf, int width, int height);

int setGameOverToScreenBuffer(char* screenBuf, int width, int height);