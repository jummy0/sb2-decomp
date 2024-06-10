// Def.h
//

#pragma once

#include <Windows.h>

#define _DEMO      FALSE  // TRUE=demo, FALSE=complet
#define _INTRO      FALSE  // TRUE si images d'introduction
#define _EGAMES      FALSE  // TRUE version pour eGames
#define _SE        FALSE  // TRUE eGames Special Edition


#define LXIMAGE      640    // dimensions de la fenêtre de jeu
#define LYIMAGE      480

#define MAXCELX      100    // nb max de cellules d'un monde
#define MAXCELY      100

//#define DIMCELX      60    // dimensions d'une cellule (décor)
//#define DIMCELY      30

//#define DIMOBJX      120    // dimensions d'un objet
//#define DIMOBJY      120

//#define DIMBLUPIX    60    // dimensions de blupi
//#define DIMBLUPIY    60
//#define SHIFTBLUPIY    5    // petit décalage vers le haut

#define DIMBUTTONX    40    // dimensions d'un button
#define DIMBUTTONY    40

#define DIMJAUGEX    124    // dimensions de la jauge
#define DIMJAUGEY    22

#define DIMTEXTX    16    // dimensions max d'un caractère
#define DIMTEXTY    16

#define DIMLITTLEX    16    // dimensions max d'un petit caractère
#define DIMLITTLEY    12

#define CHBACK     0
#define CHOBJECT   1
#define CHBLUPI    2
#define CHDECOR    3
#define CHHILI     5
#define CHFOG      6
#define CHMASK1    7
#define CHMAP      8
#define CHEXPLO    9
#define CHELEMENT  10
#define CHBLUPI001 11
#define CHBLUPI002 12
#define CHBLUPI003 13
#define CHTEMP     14


// Directions :

#define DIRECT_LEFT   1
#define DIRECT_RIGHT  2


// Actions :

#define ACTION_STOP      0    // arrêt
#define ACTION_STOPf     1    // arrêt fatigué
#define ACTION_MARCHE    2    // marche
#define ACTION_MARCHEf   3    // marche fatigué
#define ACTION_BUILD     4    // construit
#define ACTION_PIOCHE    5    // pioche
#define ACTION_ENERGY    6    // prend de l'énergie
#define ACTION_TAKE      8    // fait sauter un objet sur la tête (est)
#define ACTION_DEPOSE    9    // repose l'objet sur la tête (est)
#define ACTION_SCIE      10    // scie du bois
#define ACTION_BRULE     11    // blupi crame !
#define ACTION_TCHAO     12    // blupi disparait !
#define ACTION_MANGE     13    // blupi mange
#define ACTION_NAISSANCE 14    // naissance
#define ACTION_SAUTE2    15    // saute par-dessus un obstacle
#define ACTION_SAUTE3    16    // saute par-dessus un obstacle
#define ACTION_SAUTE4    17    // saute par-dessus un obstacle
#define ACTION_SAUTE5    18    // saute par-dessus un obstacle
#define ACTION_PONT      19    // pousse un pont
#define ACTION_MISC1     20    // divers 1 (hausse les épaules)
#define ACTION_MISC2     21    // divers 2 (grat-grat)
#define ACTION_MISC3     22    // divers 3 (yoyo)
#define ACTION_MISC1f    23    // divers 1 fatigué (bof-bof)
#define ACTION_GLISSE    24    // glisse en marchant
#define ACTION_BOIT      25    // blupi boit
#define ACTION_LABO      26    // blupi travaille dans son laboratoire
#define ACTION_DYNAMITE  27    // blupi fait péter la dynamite
#define ACTION_DELAY    28    // blupi attend un frame
#define ACTION_CUEILLE1    29    // blupi cueille des fleurs
#define ACTION_CUEILLE2    30    // blupi cueille des fleurs
#define ACTION_MECHE    31    // blupi se bouche les oreilles
#define ACTION_STOPb    32    // arrêt en bateau
#define ACTION_MARCHEb    33    // avance en bateau
#define ACTION_STOPj    34    // arrêt en jeep
#define ACTION_MARCHEj    35    // avance en jeep
#define ACTION_ELECTRO    36    // blupi électrocuté
#define ACTION_GRILLE1    37    // blupi grille (phase 1)
#define ACTION_GRILLE2    38    // blupi grille (phase 2)
#define ACTION_GRILLE3    39    // blupi grille (phase 3)
#define ACTION_MISC4    40    // divers 4 (ferme les yeux)
#define ACTION_CONTENT    41    // blupi est content
#define ACTION_ARROSE    42    // blupi arrose
#define ACTION_BECHE    43    // blupi bèche
#define ACTION_CUEILLE3    44    // blupi cueille des fleurs
#define ACTION_BUILDBREF  45    // construit
#define ACTION_BUILDSEC    46    // construit
#define ACTION_BUILDSOURD  47    // construit
#define ACTION_BUILDPIERRE  48    // construit
#define ACTION_PIOCHEPIERRE  49    // pioche
#define ACTION_PIOCHESOURD  50    // pioche
#define ACTION_MISC5    51    // divers 5 (ohé)
#define ACTION_TELEPORTE1  52    // téléporte
#define ACTION_TELEPORTE2  53    // téléporte
#define ACTION_TELEPORTE3  54    // téléporte
#define ACTION_STOPa    55    // arrêt armure
#define ACTION_MARCHEa    56    // marche armure
#define ACTION_ARMUREOPEN  57    // ouvre armure
#define ACTION_ARMURECLOSE  58    // ferme armure
#define ACTION_SAUTE1    59    // saute dans la jeep
#define ACTION_MISC6    60    // divers 6 (diabolo)

#define ACTION_A_STOP    100    // araignée: arrêt
#define ACTION_A_MARCHE    101    // araignée: marche
#define ACTION_A_SAUT    102    // araignée: saute
#define ACTION_A_GRILLE    103    // araignée: grille dans rayon
#define ACTION_A_POISON    105    // araignée: empoisonée
#define ACTION_A_MORT1    106    // araignée: meurt
#define ACTION_A_MORT2    107    // araignée: meurt
#define ACTION_A_MORT3    108    // araignée: meurt

#define ACTION_V_STOP    200    // virus: arrêt
#define ACTION_V_MARCHE    201    // virus: marche
#define ACTION_V_GRILLE    202    // virus: grille dans rayon

#define ACTION_T_STOP    300    // tracks: arrêt
#define ACTION_T_MARCHE    301    // tracks: marche
#define ACTION_T_ECRASE    302    // tracks: écrase un objet

#define ACTION_R_STOP    400    // robot: arrêt
#define ACTION_R_MARCHE    401    // robot: marche
#define ACTION_R_APLAT    402    // robot: applatit
#define ACTION_R_BUILD    403    // robot: construit
#define ACTION_R_DELAY    404    // robot: construit
#define ACTION_R_CHARGE    405    // robot: recharge
#define ACTION_R_ECRASE    406    // robot: écrase un objet

#define ACTION_B_STOP    500    // bombe: arrêt
#define ACTION_B_MARCHE    501    // bombe: marche

#define ACTION_D_DELAY    600    // détonnateur: attend

#define ACTION_E_STOP    700    // électro: arrêt
#define ACTION_E_MARCHE    701    // électro: marche
#define ACTION_E_DEBUT    702    // électro: débute
#define ACTION_E_RAYON    703    // électro: rayonne

#define ACTION_D_STOP    800    // disciple: arrêt
#define ACTION_D_MARCHE    801    // disciple: marche
#define ACTION_D_BUILD    802    // disciple: construit
#define ACTION_D_PIOCHE    803    // disciple: pioche
#define ACTION_D_SCIE    804    // disciple: scie du bois
#define ACTION_D_TCHAO    805    // disciple: disparait !
#define ACTION_D_CUEILLE1  806    // disciple: cueille des fleurs
#define ACTION_D_CUEILLE2  807    // disciple: cueille des fleurs
#define ACTION_D_MECHE    808    // disciple: se bouche les oreilles
#define ACTION_D_ARROSE    809    // disciple: arrose
#define ACTION_D_BECHE    810    // disciple: bèche


// Sons :

#define SOUND_CLICK       0
#define SOUND_JUMP_MEDIUM 1
#define SOUND_JUMP_HIGH   2
#define SOUND_STEP        3
#define SOUND_BONK        4
#define SOUND_TURN        5
#define SOUND_WHOOPS      6
#define SOUND_CROUCH      7
#define SOUND_WAH         8
#define SOUND_RESPAWN     9
#define SOUND_EXPLODE     10
#define SOUND_CHEST       11
#define SOUND_EGG         12
#define SOUND_NOT_ENOUGH  13
#define SOUND_WIN         14
#define SOUND_HELI_START  15
#define SOUND_HELI_MOVE   16
#define SOUND_HELI_STOP   17
#define SOUND_HELI_IDLE   18
#define SOUND_CHEST_LAST  19
#define SOUND_CROUCH_END  20
#define SOUND_LOOK_UP     21
#define SOUND_JUMP_LOW    22
#define SOUND_SPLASH_BIG  23
#define SOUND_BUBBLES     24
#define SOUND_GASP        25
#define SOUND_DROWN       26
#define SOUND_CANT_USE    27
#define SOUND_JEEP_START  28
#define SOUND_JEEP_MOVE   29
#define SOUND_JEEP_STOP   30
#define SOUND_JEEP_IDLE   31
#define SOUND_LEVEL_START 32
#define SOUND_DOOR_OPEN   33
#define SOUND_BAR_GRAB    34
#define SOUND_BAR_PULLUP  35
#define SOUND_MONKEY      36
#define SOUND_FOOT_TAP    37
#define SOUND_CASE_PUSH   38
#define SOUND_CASE_PULL   39
#define SOUND_HURT_HEAD   40
#define SOUND_DOINK       41
#define SOUND_SHIELD_START 42
#define SOUND_SHIELD_END  43
#define SOUND_LOLLY_START 44
#define SOUND_LOLLY_END   45
#define SOUND_PHEW        46
#define SOUND_EXHILARATED 47
#define SOUND_EFFORT      48
#define SOUND_FRIGHTEN    49
#define SOUND_LOLLY_EAT   50
#define SOUND_GLUE_HIT    51
#define SOUND_GLUE_FIRE   52
#define SOUND_NO_ITEMS    53
#define SOUND_GLUE_GET    54
#define SOUND_POWER_START 55
#define SOUND_POWER_END   56
#define SOUND_DRINK       57
#define SOUND_POWER_GET   58
#define SOUND_POWER_HIT   59
#define SOUND_BOMB_GET    60
#define SOUND_BOMB_USE    61
#define SOUND_INVIS_START 62
#define SOUND_INVIS_END   63
#define SOUND_SPLASH_SMALL 64
#define SOUND_TAUNT       65

// Speedy Blupi 2
#define SOUND_INVERT_START 66
#define SOUND_INVERT_END  67
#define SOUND_SPRING      68 // where is this used ?
#define SOUND_LIGHTNING   69
#define SOUND_CRUSH_START 70
#define SOUND_TELEPORT    71
#define SOUND_BRIDGE_BREAK 72
#define SOUND_BRIDGE_APPEAR 73
#define SOUND_DIE         74
#define SOUND_SAW_HIT     75
#define SOUND_SAW_STOP    76
#define SOUND_SAW_START   77
#define SOUND_STEP_WOOD   78
#define SOUND_BONK_WOOD   79
#define SOUND_STEP_METAL  80
#define SOUND_BONK_METAL  81
#define SOUND_STEP_CAVE   82
#define SOUND_BONK_CAVE   83
#define SOUND_STEP_SLIME  84
#define SOUND_BONK_SLIME  85
#define SOUND_STEP_PLASTIC 86
#define SOUND_BONK_PLASTIC 87
#define SOUND_STEP_CHEESE 88
#define SOUND_BONK_CHEESE 89
#define SOUND_STEP_GRASS  90
#define SOUND_BONK_GRASS  91
#define SOUND_HOMING_BOMB 92

#define SOUND_MOVIE       99


// Boutons (play) :

#define MAXBUTTON      40

/*  ?
#define BUTTON_GO      0
#define BUTTON_STOP      1
#define BUTTON_MANGE    2
#define BUTTON_CARRY    3
#define BUTTON_DEPOSE    4
#define BUTTON_ABAT      5
#define BUTTON_ROC      6
#define BUTTON_CULTIVE    7
#define BUTTON_BUILD1    8
#define BUTTON_BUILD2    9
#define BUTTON_BUILD3    10
#define BUTTON_BUILD4    11
#define BUTTON_BUILD5    12
#define BUTTON_BUILD6    13
#define BUTTON_MUR      14
#define BUTTON_PALIS    15
#define BUTTON_ABATn    16
#define BUTTON_ROCn      17
#define BUTTON_PONT      18
#define BUTTON_TOUR      19
#define BUTTON_BOIT      20
#define BUTTON_LABO      21
#define BUTTON_FLEUR    22
#define BUTTON_FLEURn    23
#define BUTTON_DYNAMITE    24
#define BUTTON_BATEAU    25
#define BUTTON_DJEEP    26
#define BUTTON_DRAPEAU    27
#define BUTTON_EXTRAIT    28
#define BUTTON_FABJEEP    29
#define BUTTON_FABMINE    30
#define BUTTON_FABDISC    31
#define BUTTON_REPEAT    32
#define BUTTON_DARMURE    33
#define BUTTON_FABARMURE  34
*/

// Lutins pour la souris

#define SPRITE_ARROW    1
#define SPRITE_POINTER    2
#define SPRITE_MAP      3
#define SPRITE_ARROWU    4
#define SPRITE_ARROWD    5
#define SPRITE_ARROWL    6
#define SPRITE_ARROWR    7
#define SPRITE_ARROWUL    8
#define SPRITE_ARROWUR    9
#define SPRITE_ARROWDL    10
#define SPRITE_ARROWDR    11
#define SPRITE_WAIT      12
#define SPRITE_EMPTY    13
#define SPRITE_FILL      14


// User define message

#define WM_UPDATE        (WM_USER+1)

#define WM_DECOR1        (WM_USER+20)
#define WM_DECOR2        (WM_USER+21)
#define WM_DECOR3        (WM_USER+22)
#define WM_DECOR4        (WM_USER+23)
#define WM_DECOR5        (WM_USER+24)

#define WM_BUTTON0        (WM_USER+200)
#define WM_BUTTON1        (WM_USER+201)
#define WM_BUTTON2        (WM_USER+202)
#define WM_BUTTON3        (WM_USER+203)
#define WM_BUTTON4        (WM_USER+204)
#define WM_BUTTON5        (WM_USER+205)
#define WM_BUTTON6        (WM_USER+206)
#define WM_BUTTON7        (WM_USER+207)
#define WM_BUTTON8        (WM_USER+208)
#define WM_BUTTON9        (WM_USER+209)
#define WM_BUTTON10        (WM_USER+210)
#define WM_BUTTON11        (WM_USER+211)
#define WM_BUTTON12        (WM_USER+212)
#define WM_BUTTON13        (WM_USER+213)
#define WM_BUTTON14        (WM_USER+214)
#define WM_BUTTON15        (WM_USER+215)
#define WM_BUTTON16        (WM_USER+216)
#define WM_BUTTON17        (WM_USER+217)
#define WM_BUTTON18        (WM_USER+218)
#define WM_BUTTON19        (WM_USER+219)
#define WM_BUTTON20        (WM_USER+220)
#define WM_BUTTON21        (WM_USER+221)
#define WM_BUTTON22        (WM_USER+222)
#define WM_BUTTON23        (WM_USER+223)
#define WM_BUTTON24        (WM_USER+224)
#define WM_BUTTON25        (WM_USER+225)
#define WM_BUTTON26        (WM_USER+226)
#define WM_BUTTON27        (WM_USER+227)
#define WM_BUTTON28        (WM_USER+228)
#define WM_BUTTON29        (WM_USER+229)
#define WM_BUTTON30        (WM_USER+230)
#define WM_BUTTON31        (WM_USER+231)
#define WM_BUTTON32        (WM_USER+232)
#define WM_BUTTON33        (WM_USER+233)
#define WM_BUTTON34        (WM_USER+234)
#define WM_BUTTON35        (WM_USER+235)
#define WM_BUTTON36        (WM_USER+236)
#define WM_BUTTON37        (WM_USER+237)
#define WM_BUTTON38        (WM_USER+238)
#define WM_BUTTON39        (WM_USER+239)

#define WM_READ0        (WM_USER+300)
#define WM_READ1        (WM_USER+301)
#define WM_READ2        (WM_USER+302)
#define WM_READ3        (WM_USER+303)
#define WM_READ4        (WM_USER+304)
#define WM_READ5        (WM_USER+305)
#define WM_READ6        (WM_USER+306)
#define WM_READ7        (WM_USER+307)
#define WM_READ8        (WM_USER+308)
#define WM_READ9        (WM_USER+309)

#define WM_WRITE0        (WM_USER+310)
#define WM_WRITE1        (WM_USER+311)
#define WM_WRITE2        (WM_USER+312)
#define WM_WRITE3        (WM_USER+313)
#define WM_WRITE4        (WM_USER+314)
#define WM_WRITE5        (WM_USER+315)
#define WM_WRITE6        (WM_USER+316)
#define WM_WRITE7        (WM_USER+317)
#define WM_WRITE8        (WM_USER+318)
#define WM_WRITE9        (WM_USER+319)


#define WM_PHASE_INIT      (WM_USER+500) //0x5F4
#define WM_PHASE_PLAY      (WM_USER+501)
#define WM_PHASE_BUILD      (WM_USER+502)
//#define WM_PHASE_READ      (WM_USER+503)
//#define WM_PHASE_WRITE      (WM_USER+504)
//#define WM_PHASE_INFO      (WM_USER+505)
//#define WM_PHASE_BUTTON      (WM_USER+506)
//#define WM_PHASE_TERM      (WM_USER+507)
//#define WM_PHASE_WIN      (WM_USER+508)
//#define WM_PHASE_LOST      (WM_USER+509)
//#define WM_PHASE_STOP      (WM_USER+510)
//#define WM_PHASE_SETUP      (WM_USER+511)
//#define WM_PHASE_MUSIC      (WM_USER+512) // 0x600
//#define WM_PHASE_PLAYMOVIE    (WM_USER+513)
//#define WM_PHASE_WINMOVIE    (WM_USER+514)
//#define WM_PHASE_SCHOOL      (WM_USER+515)
//#define WM_PHASE_MISSION    (WM_USER+516)
//#define WM_PHASE_LASTWIN    (WM_USER+517)
//#define WM_PHASE_WRITEp      (WM_USER+518)
//#define WM_PHASE_SETUPp      (WM_USER+519)
//#define WM_PHASE_REGION      (WM_USER+520)
//#define WM_PHASE_INSERT      (WM_USER+521)
//#define WM_PHASE_HISTORY0    (WM_USER+522)
//#define WM_PHASE_HISTORY1    (WM_USER+523)
//#define WM_PHASE_HELP      (WM_USER+524)
//#define WM_PHASE_H0MOVIE    (WM_USER+525)
//#define WM_PHASE_H1MOVIE    (WM_USER+526)
//#define WM_PHASE_H2MOVIE    (WM_USER+527)
#define WM_PHASE_TESTCD      (WM_USER+528) // 0x610
#define WM_PHASE_MANUEL      (WM_USER+529)
//#define WM_PHASE_PRIVATE    (WM_USER+530)
//#define WM_PHASE_UNDO      (WM_USER+531)
#define WM_PHASE_BYE      (WM_USER+532)
//#define WM_PHASE_SKILL1      (WM_USER+533)
//#define WM_PHASE_SKILL2      (WM_USER+534)
#define WM_PHASE_DEMO      (WM_USER+535)
#define WM_PHASE_INTRO1      (WM_USER+536)
#define WM_PHASE_INTRO2      (WM_USER+537)

#define WM_PREV          (WM_USER+600)
#define WM_NEXT          (WM_USER+601)
#define WM_MOVIE        (WM_USER+602)




// Types de gestion de la souris.

#define MOUSETYPEGRA      1
#define MOUSETYPEWIN      2
#define MOUSETYPEWINPOS      3
*/
