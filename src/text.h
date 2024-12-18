// Text.h
#ifndef TEXT_H
#define TEXT_H

#define FONTWHITE  0
#define FONTGOLD    1
#define FONTSELECTED   2
#define FONTLITTLE 10

typedef struct
{
    char  charIcon;
    char  charOffsetX;
    char  charOffsetY;
    char  accentIcon;
    char  accentOffsetX;
    char  accentOffsetY;
}
CharOffset;

extern
void DrawText(CPixmap *pPixmap, POINT pos, char *pText, int font);

extern
void DrawTextLeft(CPixmap* pPixmap, POINT pos, char *text, int font);

extern
void DrawTextNew(CPixmap *pPixmap, POINT pos, char* pText, int font);

extern
void DrawChar(CPixmap* pPixmap, POINT* pos, char c, int font);

extern
void DrawCharSingle(CPixmap* pPixmap, POINT pos, int rank, int font);

extern
void DrawTextNew(CPixmap* pPixmap, POINT pos, char* pText, int font);

extern
void DrawTextPente(CPixmap *pPixmap, POINT pos, char *pText,
                   int pente, int font=0);

extern
void DrawTextRect(CPixmap *pPixmap, POINT pos, char *pText,
                  int pente, int font=0, int part=-1);

extern
void DrawTextCenter(CPixmap *pPixmap, POINT pos, char *pText, int font=0);

extern
int GetTextHeight(char *pText, int font=0, int part=-1);

extern
int GetTextWidth(char *pText, int font=0);

extern
void DrawBignum(CPixmap *pPixmap, POINT pos, int num);

extern
int GetBignumWidth(int num);

#endif