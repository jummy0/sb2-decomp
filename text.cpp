// Text.cpp

#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <ddraw.h>
#include "def.h"
#include "pixmap.h"
#include "text.h"
#include "texttables.h"

/////////////////////////////////////////////////////////////////////////////

static CharOffset table_offsets[] =
{
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ ' ',	0,	0,	-1,	0,	0 },
	{ '!',	0,	0,	-1,	0,	0 },
	{ '"',	0,	0,	-1,	0,	0 },
	{ '#',	0,	0,	-1,	0,	0 },
	{ '$',	0,	0,	-1,	0,	0 },
	{ '%',	0,	0,	-1,	0,	0 },
	{ '&',	0,	0,	-1,	0,	0 },
	{ '\'',	0,	0,	-1,	0,	0 },
	{ '(',	0,	0,	-1,	0,	0 },
	{ ')',	0,	0,	-1,	0,	0 },
	{ '*',	0,	0,	-1,	0,	0 },
	{ '+',	0,	0,	-1,	0,	0 },
	{ ',',	0,	0,	-1,	0,	0 },
	{ '-',	0,	0,	-1,	0,	0 },
	{ '.',	0,	0,	-1,	0,	0 },
	{ '/',	0,	0,	-1,	0,	0 },
	{ '0',	0,	0,	-1,	0,	0 },
	{ '1',	0,	0,	-1,	0,	0 },
	{ '2',	0,	0,	-1,	0,	0 },
	{ '3',	0,	0,	-1,	0,	0 },
	{ '4',	0,	0,	-1,	0,	0 },
	{ '5',	0,	0,	-1,	0,	0 },
	{ '6',	0,	0,	-1,	0,	0 },
	{ '7',	0,	0,	-1,	0,	0 },
	{ '8',	0,	0,	-1,	0,	0 },
	{ '9',	0,	0,	-1,	0,	0 },
	{ ':',	0,	0,	-1,	0,	0 },
	{ ';',	0,	0,	-1,	0,	0 },
	{ '<',	0,	0,	-1,	0,	0 },
	{ '=',	0,	0,	-1,	0,	0 },
	{ '>',	0,	0,	-1,	0,	0 },
	{ '?',	0,	0,	-1,	0,	0 },
	{ '@',	0,	0,	-1,	0,	0 },
	{ 'A',	0,	0,	-1,	0,	0 },
	{ 'B',	0,	0,	-1,	0,	0 },
	{ 'C',	0,	0,	-1,	0,	0 },
	{ 'D',	0,	0,	-1,	0,	0 },
	{ 'E',	0,	0,	-1,	0,	0 },
	{ 'F',	0,	0,	-1,	0,	0 },
	{ 'G',	0,	0,	-1,	0,	0 },
	{ 'H',	0,	0,	-1,	0,	0 },
	{ 'I',	0,	0,	-1,	0,	0 },
	{ 'J',	0,	0,	-1,	0,	0 },
	{ 'K',	0,	0,	-1,	0,	0 },
	{ 'L',	0,	0,	-1,	0,	0 },
	{ 'M',	0,	0,	-1,	0,	0 },
	{ 'N',	0,	0,	-1,	0,	0 },
	{ 'O',	0,	0,	-1,	0,	0 },
	{ 'P',	0,	0,	-1,	0,	0 },
	{ 'Q',	0,	0,	-1,	0,	0 },
	{ 'R',	0,	0,	-1,	0,	0 },
	{ 'S',	0,	0,	-1,	0,	0 },
	{ 'T',	0,	0,	-1,	0,	0 },
	{ 'U',	0,	0,	-1,	0,	0 },
	{ 'V',	0,	0,	-1,	0,	0 },
	{ 'W',	0,	0,	-1,	0,	0 },
	{ 'X',	0,	0,	-1,	0,	0 },
	{ 'Y',	0,	0,	-1,	0,	0 },
	{ 'Z',	0,	0,	-1,	0,	0 },
	{ '[',	0,	0,	-1,	0,	0 },
	{ '\\',	0,	0,	-1,	0,	0 },
	{ ']',	0,	0,	-1,	0,	0 },
	{ '^',	0,	0,	-1,	0,	0 },
	{ '_',	0,	0,	-1,	0,	0 },
	{ '`',	0,	0,	-1,	0,	0 },
	{ 'a',	0,	0,	-1,	0,	0 },
	{ 'b',	0,	0,	-1,	0,	0 },
	{ 'c',	0,	0,	-1,	0,	0 },
	{ 'd',	0,	0,	-1,	0,	0 },
	{ 'e',	0,	0,	-1,	0,	0 },
	{ 'f',	0,	0,	-1,	0,	0 },
	{ 'g',	0,	0,	-1,	0,	0 },
	{ 'h',	0,	0,	-1,	0,	0 },
	{ 'i',	0,	0,	-1,	0,	0 },
	{ 'j',	0,	0,	-1,	0,	0 },
	{ 'k',	0,	0,	-1,	0,	0 },
	{ 'l',	0,	0,	-1,	0,	0 },
	{ 'm',	0,	0,	-1,	0,	0 },
	{ 'n',	0,	0,	-1,	0,	0 },
	{ 'o',	0,	0,	-1,	0,	0 },
	{ 'p',	0,	0,	-1,	0,	0 },
	{ 'q',	0,	0,	-1,	0,	0 },
	{ 'r',	0,	0,	-1,	0,	0 },
	{ 's',	0,	0,	-1,	0,	0 },
	{ 't',	0,	0,	-1,	0,	0 },
	{ 'u',	0,	0,	-1,	0,	0 },
	{ 'v',	0,	0,	-1,	0,	0 },
	{ 'w',	0,	0,	-1,	0,	0 },
	{ 'x',	0,	0,	-1,	0,	0 },
	{ 'y',	0,	0,	-1,	0,	0 },
	{ 'z',	0,	0,	-1,	0,	0 },
	{ '{',	0,	0,	-1,	0,	0 },
	{ '|',	0,	0,	-1,	0,	0 },
	{ '}',	0,	0,	-1,	0,	0 },
	{ '~',	0,	0,	-1,	0,	0 },
	{ 0x7f,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 0x05,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 0x04,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 0x10,	0,	0,	-1,	0,	0 },
	{ 'a',	0,	0,	2,	2,	0 },
	{ 0x11,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 0x1b,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 0x1d,	0,	0,	-1,	0,	0 },
	{ 0x13,	0,	0,	-1,	0,	0 },
	{ 0x12,	0,	0,	-1,	0,	0 },
	{ 0x15,	0,	0,	-1,	0,	0 },
	{ 0x14,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 'i',	0,	0,	2,	-1,	0 },
	{ 0x17,	0,	0,	-1,	0,	0 },
	{ 0x16,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 'n',	0,	0,	'~',	-1,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 'o',	0,	0,	2,	1,	0 },
	{ 0x18,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 0x1c,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 0x19,	0,	0,	-1,	0,	0 },
	{ 'u',	0,	0,	2,	2,	0 },
	{ 0x1a,	0,	0,	-1,	0,	0 },
	{ 0x0f,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 },
	{ 1,	0,	0,	-1,	0,	0 }
};

// Retourne l'offset pour un caract�re donn�.

int GetOffset(char c)
{
	int		i;

	static unsigned char table_accents[15] =
	{
		0xFC, 0xE0, 0xE2, 0xE9, 0xE8, 0xEB, 0xEA, 0xEF,
		0xEE, 0xF4, 0xF9, 0xFB, 0xE4, 0xF6, 0xE7
	};

	for ( i=0 ; i<15 ; i++ )
	{
		if ( (unsigned char)c == table_accents[i] )
		{
			return 15+i;
		}
	}
	if ( c<0 || c>128 )  return 1;  // carr�

	return c;
}

// Retourne la longueur d'un caract�re.

int GetCharWidthB(char c, int font)
{
	static unsigned char table_width[128] =
	{
		9,10,10,10,10,10,10,10,10,10,10,10,10,10,10,8,
		9,9,8,8,8,8,5,5,8,8,8,9,8,8,10,10,
		5,6,9,13,11,12,12,6,6,6,12,12,5,9,6,9,
		8,8,9,9,8,9,8,8,9,9,6,6,8,9,10,11,
		12,8,9,9,9,8,8,8,9,4,8,9,8,10,9,9,
		8,9,8,9,10,8,9,11,9,8,10,7,10,7,13,13,
		9,9,8,8,8,8,6,8,8,4,6,8,4,12,8,8,
		8,8,7,6,7,8,8,10,8,8,7,6,6,6,10,0,
	};

	static unsigned char table_width_little[128] =
	{
		6,6,6,6,6,6,6,6,6,6,6,6,5,6,6,7,
		6,6,6,6,6,6,3,3,6,6,6,6,6,6,5,5,
		3,3,5,8,5,11,9,3,4,4,6,6,3,4,3,6,
		5,5,5,5,5,5,5,5,5,5,3,3,7,6,7,6,
		9,8,6,7,7,5,5,8,7,2,4,7,5,10,7,8,
		6,8,7,6,6,6,8,12,7,6,6,3,5,3,6,8,
		4,6,6,6,6,6,4,6,6,2,3,5,2,10,6,6,
		6,6,3,5,3,6,6,8,6,6,5,4,6,4,7,0,
	};

	if ( font == FONTLITTLE )
	{
		return table_width_little[GetOffset(c)];
	}
	else
	{
		return table_width[GetOffset(c)]-1;
	}
}

void DrawCharSingle(CPixmap *pPixmap, POINT pos, char *pText, int font)
{
	if (font == FONTLITTLE)
	{
		pPixmap->DrawIcon(-1, CHLITTLE, *pText, pos, 0, FALSE);
	}
	else
	{
		pPixmap->DrawIcon(-1, CHTEXT, *pText + font * 128, pos, 0, FALSE);
	}
}

void DrawChar(CPixmap *pPixmap, POINT *pos, char c, int font)
{
	POINT pos2 { table_offsets[c].charOffsetX + pos->x, table_offsets[c].charOffsetY + pos->y };
	DrawCharSingle(pPixmap, pos2, &table_offsets[c].charIcon, font);
	if (table_offsets[c].accentIcon != -1)
	{
		pos2 = { table_offsets[c].accentOffsetX + pos->x, table_offsets[c].accentOffsetY + pos->y };
		DrawCharSingle(pPixmap, pos2, &table_offsets[c].accentIcon, font);
	}
	pos->x += GetCharWidthB(c, font);
}

void DrawTextLeft(CPixmap *pPixmap, POINT pos, char *pText, int font)
{
	DrawTextB(pPixmap, pos, pText, font);
}

// Affiche un texte.

void DrawTextB(CPixmap *pPixmap, POINT pos, char *pText, int font)
{
	while (*pText != 0)
	{
		DrawChar(pPixmap, &pos, *pText++, font);
	}
}

// Affiche un texte penché.

void DrawTextPente(CPixmap *pPixmap, POINT pos, char *pText,
	int pente, int font)
{
	int		rank, lg, rel, start;

	start = pos.y;
	rel = 0;
	while (*pText != 0)
	{
		rank = GetOffset(*pText);
		rank += 128 * font;
		pPixmap->DrawIcon(-1, CHTEXT, rank, pos);

		lg = GetCharWidthB(*pText++, font);
		rel += lg;
		pos.x += lg;
		pos.y = start + rel / pente;
	}
}

// Affiche un pavé de texte.
// Une ligne vide est affichée avec un demi interligne !
// Si part != -1, n'affiche que les lignes qui commencent
// par "n|", avec n=part.

void DrawTextRect(CPixmap *pPixmap, POINT pos, char *pText,
	int pente, int font, int part)
{
	char		text[100];
	char*		pDest;
	int			itl;

	if (font == FONTLITTLE)  itl = DIMLITTLEY;
	else                       itl = DIMTEXTY;

	while (*pText != 0)
	{
		pDest = text;
		while (*pText != 0 && *pText != '\r' && *pText != '\n')
		{
			*pDest++ = *pText++;
		}
		*pDest = 0;
		if (*pText == '\r')  pText++;  // saute '\r'
		if (*pText == '\n')  pText++;  // saute '\n'

		pDest = text;
		if (text[0] != 0 && text[1] == '|')  // commence par "n|" ?
		{
			if (part != -1 && part != text[0] - '0')  continue;
			pDest += 2;  // saute "n|"
		}
		else
		{
			if (part != -1)  continue;
		}

		if (pente == 0)
		{
			DrawTextB(pPixmap, pos, pDest, font);
		}
		else
		{
			DrawTextPente(pPixmap, pos, pDest, pente, font);
		}

		if (pDest[0] == 0)  // ligne vide ?
		{
			pos.y += itl / 2;  // descend de 1/2 ligne
		}
		else
		{
			pos.y += itl;  // passe à la ligne suivante
		}
	}
}

// Affiche un texte centré pouvant éventuellement
// contenir plusieurs lignes séparées par des '\n'.

void DrawTextCenter(CPixmap *pPixmap, POINT pos, char *pText, int font)
{
	char		text[100];
	char*		pDest;
	int			itl;
	POINT		start;

	if (font == FONTLITTLE)  itl = DIMLITTLEY;
	else                       itl = DIMTEXTY;

	while (*pText != 0)
	{
		pDest = text;
		while (*pText != 0 && *pText != '\r' && *pText != '\n')
		{
			*pDest++ = *pText++;
		}
		*pDest = 0;
		if (*pText == '\r')  pText++;  // saute '\r'
		if (*pText == '\n')  pText++;  // saute '\n'

		pDest = text;
		start.x = pos.x - GetTextWidth(pDest) / 2;
		start.y = pos.y;
		DrawTextB(pPixmap, start, pDest, font);

		if (pDest[0] == 0)  // ligne vide ?
		{
			pos.y += itl / 2;  // descend de 1/2 ligne
		}
		else
		{
			pos.y += itl;  // passe à la ligne suivante
		}
	}
}

// Retourne la hauteur d'un texte.

int GetTextHeight(char *pText, int font, int part)
{
	char		text[100];
	char*		pDest;
	int			itl;
	int			h = 0;

	if (font == FONTLITTLE)  itl = DIMLITTLEY;
	else                       itl = DIMTEXTY;

	while (*pText != 0)
	{
		pDest = text;
		while (*pText != 0 && *pText != '\r' && *pText != '\n')
		{
			*pDest++ = *pText++;
		}
		*pDest = 0;
		if (*pText == '\r')  pText++;  // saute '\r'
		if (*pText == '\n')  pText++;  // saute '\n'

		pDest = text;
		if (text[0] != 0 && text[1] == '|')  // commence par "n|" ?
		{
			if (part != -1 && part != text[0] - '0')  continue;
			pDest += 2;  // saute "n|"
		}
		else
		{
			if (part != -1)  continue;
		}

		if (pDest[0] == 0)  // ligne vide ?
		{
			h += itl / 2;  // descend de 1/2 ligne
		}
		else
		{
			h += itl;  // passe à la ligne suivante
		}
	}

	return h;
}

// Retourne la longueur d'un texte.

int GetTextWidth(char *pText, int font)
{
	int		width = 0;

	while (*pText != 0)
	{
		width += GetCharWidthB(*pText++, font);
	}

	return width;
}
