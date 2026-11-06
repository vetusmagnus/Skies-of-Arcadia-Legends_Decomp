#include "types.h"
#include <stdlib.h>
#include "game/save_8030B7F4.h"
#include "game/gamedata.h"
#include "game/stat_8030B4D4.h"
/* .data 0x802F6918-0x802F7208: the text tables fn_801F48AC picks from. The unit defines them, so
 * MWCC reaches all of them from one base register (lbl_802F6918). lbl_802F6F10 and lbl_802F70F0
 * have no symbol in symbols.txt yet (they are the second halves of lbl_802F6DD0 and lbl_802F7050). */
extern const char lbl_802C9668[], lbl_802C96C4[], lbl_802C9724[], lbl_802C9780[], lbl_802C97DC[], lbl_802C983C[], lbl_802C9898[], lbl_802C98F8[], lbl_802C9958[], lbl_802C99B8[], lbl_802C9A1C[], lbl_802C9A7C[], lbl_802C9ADC[], lbl_802C9B3C[], lbl_802C9B9C[], lbl_802C9BFC[], lbl_802C9C60[], lbl_802C9CC0[], lbl_802C9D20[], lbl_802C9D80[], lbl_802C9DE4[], lbl_802C9E44[], lbl_802C9EA4[], lbl_802C9F04[], lbl_802C9F64[], lbl_802C9FC0[], lbl_802CA01C[], lbl_802CA078[], lbl_802CA0D8[], lbl_802CA13C[], lbl_802CA19C[], lbl_802CA1FC[], lbl_802CA25C[], lbl_802CA2BC[], lbl_802CA320[], lbl_802CA380[], lbl_802CA3E0[], lbl_802CA43C[], lbl_802CA4A0[], lbl_802CA500[], lbl_802CA55C[], lbl_802CA5BC[], lbl_802CA618[], lbl_802CA67C[], lbl_802CA6DC[], lbl_802CA740[], lbl_802CA7A0[], lbl_802CA800[], lbl_802CA860[], lbl_802CA8C0[], lbl_802CA920[], lbl_802CA980[], lbl_802CA9E4[], lbl_802CAA44[], lbl_802CAAA4[], lbl_802CAB08[], lbl_802CAB64[], lbl_802CABC0[], lbl_802CAC1C[], lbl_802CAC7C[], lbl_802CACDC[], lbl_802CAD3C[], lbl_802CAD9C[], lbl_802CADFC[], lbl_802CAE5C[], lbl_802CAEB4[], lbl_802CAF0C[], lbl_802CAF6C[], lbl_802CAFCC[], lbl_802CB02C[], lbl_802CB08C[], lbl_802CB0E4[], lbl_802CB140[], lbl_802CB19C[], lbl_802CB1F8[], lbl_802CB248[], lbl_802CB294[], lbl_802CB2F0[], lbl_802CB350[], lbl_802CB3A0[], lbl_802CB3FC[], lbl_802CB450[], lbl_802CB4AC[], lbl_802CB504[], lbl_802CB564[], lbl_802CB5C4[], lbl_802CB620[], lbl_802CB678[], lbl_802CB6D8[], lbl_802CB734[], lbl_802CB790[], lbl_802CB7F0[], lbl_802CB848[], lbl_802CB8A0[], lbl_802CB900[], lbl_802CB958[], lbl_802CB9A8[], lbl_802CB9E0[], lbl_802CBA1C[], lbl_802CBA68[], lbl_802CBAAC[], lbl_802CBAF0[], lbl_802CBB3C[], lbl_802CBB9C[], lbl_802CBBF0[], lbl_802CBC50[], lbl_802CBCB0[], lbl_802CBD10[], lbl_802CBD68[], lbl_802CBDBC[], lbl_802CBE10[], lbl_802CBE68[], lbl_802CBEB8[], lbl_802CBF08[], lbl_802CBF68[], lbl_802CBFB4[], lbl_802CC014[], lbl_802CC074[], lbl_802CC0D0[], lbl_802CC12C[], lbl_802CC188[], lbl_802CC1E0[], lbl_802CC238[], lbl_802CC288[], lbl_802CC2E4[], lbl_802CC33C[], lbl_802CC398[], lbl_802CC3EC[], lbl_802CC44C[], lbl_802CC4A4[], lbl_802CC504[], lbl_802CC558[], lbl_802CC5B4[], lbl_802CC608[], lbl_802CC658[], lbl_802CC6B0[], lbl_802CC704[], lbl_802CC714[], lbl_802CC74C[], lbl_802CC78C[], lbl_802CC7D4[], lbl_802CC820[], lbl_802CC870[], lbl_802CC8CC[], lbl_802CC90C[], lbl_802CC944[], lbl_802CC994[], lbl_802CC9F0[], lbl_802CCA34[], lbl_802CCA78[], lbl_802CCAC0[], lbl_802CCB1C[], lbl_802CCB70[], lbl_802CCBA8[], lbl_802CCC00[], lbl_802CCC4C[], lbl_802CCC80[], lbl_802CCCD4[], lbl_802CCD14[], lbl_802CCD70[], lbl_802CCDA8[], lbl_802CCDF8[], lbl_802CCE50[], lbl_802CCEAC[], lbl_802CCF08[], lbl_802CCF60[], lbl_802CCFBC[], lbl_802CD008[], lbl_802CD058[], lbl_802CD0AC[], lbl_802CD104[], lbl_802CD148[], lbl_802CD180[], lbl_802CD1DC[], lbl_802CD228[], lbl_802CD274[], lbl_802CD2B4[], lbl_802CD304[], lbl_802CD35C[], lbl_802CD3AC[], lbl_802CD3FC[], lbl_802CD444[], lbl_802CD480[], lbl_802CD4D8[], lbl_802CD514[], lbl_802CD56C[], lbl_802CD5A8[], lbl_802CD5E8[], lbl_802CD640[], lbl_802CD688[], lbl_802CD6D8[], lbl_802CD70C[], lbl_802CD754[], lbl_802CD7AC[], lbl_802CD7E4[], lbl_802CD834[], lbl_802CD880[], lbl_802CD8D4[], lbl_802CD934[], lbl_802CD988[], lbl_802CD9CC[], lbl_802CDA28[], lbl_802CDA7C[], lbl_802CDADC[], lbl_802CDB30[], lbl_802CDB74[], lbl_802CDBCC[], lbl_802CDC0C[], lbl_802CDC5C[], lbl_802CDCAC[], lbl_802CDD00[], lbl_802CDD4C[], lbl_802CDDA4[], lbl_802CDDEC[], lbl_802CDE34[], lbl_802CDE88[], lbl_802CDEE0[], lbl_802CDF3C[], lbl_802CDF90[], lbl_802CDFE8[], lbl_802CE040[], lbl_802CE07C[], lbl_802CE0D0[], lbl_802CE12C[], lbl_802CE184[], lbl_802CE1C4[], lbl_802CE21C[], lbl_802CE278[], lbl_802CE2C8[], lbl_802CE328[], lbl_802CE374[], lbl_802CE3C8[], lbl_802CE414[], lbl_802CE46C[], lbl_802CE4B4[], lbl_802CE510[], lbl_802CE548[], lbl_802CE5A4[], lbl_802CE5D4[], lbl_802CE620[], lbl_802CE67C[], lbl_802CE6C4[], lbl_802CE708[], lbl_802CE750[], lbl_802CE7AC[], lbl_802CE80C[], lbl_802CE868[], lbl_802CE8C0[], lbl_802CE918[], lbl_802CE974[], lbl_802CE9C4[], lbl_802CEA20[], lbl_802CEA78[], lbl_802CEACC[], lbl_802CEB20[], lbl_802CEB6C[], lbl_802CEBAC[], lbl_802CEBEC[], lbl_802CEC30[], lbl_802CEC88[], lbl_802CECE0[], lbl_802CED3C[], lbl_802CED98[], lbl_802CEDF0[], lbl_802CEE40[], lbl_802CEE8C[], lbl_802CEED8[], lbl_802CEF18[], lbl_802CEF5C[], lbl_802CEFB8[], lbl_802CF01C[], lbl_802CF058[], lbl_802CF0A0[], lbl_802CF0F0[], lbl_802CF13C[], lbl_802CF17C[], lbl_802CF1B8[], lbl_802CF1F0[], lbl_802CF24C[], lbl_802CF2AC[], lbl_802CF304[], lbl_802CF35C[], lbl_802CF3B4[], lbl_802CF414[], lbl_802CF46C[], lbl_802CF4C4[], lbl_802CF51C[], lbl_802CF57C[], lbl_802CF5D0[], lbl_802CF628[], lbl_802CF680[], lbl_802CF6D4[], lbl_802CF728[], lbl_802CF788[], lbl_802CF7E0[], lbl_802CF83C[], lbl_802CF890[], lbl_802CF8EC[], lbl_802CF944[], lbl_802CF99C[], lbl_802CF9F0[], lbl_802CFA44[], lbl_802CFAA0[], lbl_802CFAD8[], lbl_802CFB10[], lbl_802CFB6C[], lbl_802CFBC4[], lbl_802CFC04[], lbl_802CFC60[], lbl_802CFCA4[], lbl_802CFCEC[], lbl_802CFD40[], lbl_802CFDA0[], lbl_802CFDD8[], lbl_802CFE2C[], lbl_802CFE88[], lbl_802CFEDC[], lbl_802CFF30[], lbl_802CFF84[], lbl_802CFFC8[], lbl_802D000C[], lbl_802D0068[], lbl_802D00A8[], lbl_802D00F4[], lbl_802D0148[], lbl_802D0194[], lbl_802D01F0[], lbl_802D0250[], lbl_802D02A8[], lbl_802D0300[], lbl_802D0354[], lbl_802D03B0[], lbl_802D03F8[], lbl_802D0450[], lbl_802D0498[], lbl_802D04EC[], lbl_802D0548[], lbl_802D05A4[], lbl_802D0600[], lbl_802D065C[], lbl_802D06B8[], lbl_802D06C4[], lbl_802D0718[], lbl_802D0768[], lbl_802D07BC[], lbl_802D0818[], lbl_802D0870[], lbl_802D08CC[], lbl_802D0924[], lbl_802D097C[], lbl_802D09D8[], lbl_802D0A2C[], lbl_802D0A84[], lbl_802D0AE0[], lbl_802D0B2C[], lbl_802D0B70[], lbl_802D0BC4[], lbl_802D0C18[], lbl_802D0C28[], lbl_802D0C7C[], lbl_802D0CD4[], lbl_802D0D2C[], lbl_802D0D88[], lbl_802D0DEC[], lbl_802D0E34[], lbl_802D0E98[], lbl_802D0EF0[], lbl_802D0F44[], lbl_802D0F98[], lbl_802D0FF4[], lbl_802D1054[], lbl_802D10AC[], lbl_802D1104[], lbl_802D1164[], lbl_802D11C4[], lbl_802D1220[], lbl_802D1278[], lbl_802D12CC[], lbl_802D1324[], lbl_802D1380[], lbl_802D13E0[], lbl_802D142C[], lbl_802D1488[], lbl_802D14D4[], lbl_802D1514[], lbl_802D1568[], lbl_802D15A0[], lbl_802D15F4[], lbl_802D1644[], lbl_802D1694[], lbl_802D16CC[], lbl_802D1710[], lbl_802D1760[], lbl_802D179C[], lbl_802D17E8[], lbl_802D1844[], lbl_802D18A4[], lbl_802D1904[], lbl_802D1960[], lbl_802D19B4[], lbl_802D1A00[], lbl_802D1A54[], lbl_802D1AB4[], lbl_802D1B00[], lbl_802D1B58[], lbl_802D1BB8[], lbl_802D1C00[], lbl_802D1C60[], lbl_802D1CA8[], lbl_802D1CF8[], lbl_802D1D40[], lbl_802D1D94[], lbl_802D1DEC[], lbl_802D1E40[], lbl_802D1E9C[], lbl_802D1EF8[], lbl_802D1F58[], lbl_802D1FB8[], lbl_802D2008[], lbl_802D2058[], lbl_802D20B0[], lbl_802D20F0[], lbl_802D2138[], lbl_802D218C[], lbl_802D21C8[], lbl_802D21F4[], lbl_802D2244[], lbl_802D22A0[], lbl_802D22FC[], lbl_802D2338[], lbl_802D2394[], lbl_802D23E4[], lbl_802D2434[], lbl_802D2498[], lbl_802D24EC[], lbl_802D254C[], lbl_802D2590[], lbl_802D25D8[], lbl_802D2638[], lbl_802D2684[], lbl_802D26DC[], lbl_802D272C[], lbl_802D278C[], lbl_802D27E4[], lbl_802D2840[], lbl_802D2898[], lbl_802D28EC[], lbl_802D2938[], lbl_802D2988[], lbl_802D29E0[], lbl_802D2A28[], lbl_802D2A84[], lbl_802D2ADC[], lbl_802D2B38[], lbl_802D2B90[], lbl_802D2BF0[], lbl_802D2C20[], lbl_802D2C74[], lbl_802D2CC4[], lbl_802D2D1C[], lbl_802D2D74[], lbl_802D2DD0[], lbl_802D2E2C[], lbl_802D2E88[], lbl_802D2EE0[], lbl_802D2F3C[], lbl_802D2F80[], lbl_802D2FC8[], lbl_802D3024[], lbl_802D306C[], lbl_802D30B8[], lbl_802D3108[], lbl_802D3168[], lbl_802D31C4[], lbl_802D3220[], lbl_802D3264[], lbl_802D32AC[], lbl_802D3308[], lbl_802D3350[], lbl_802D33B0[], lbl_802D340C[], lbl_802D3460[], lbl_802D34AC[], lbl_802D3508[], lbl_802D3564[];
const char *lbl_802F6918[62] = {
    lbl_802C9668, lbl_802C96C4, lbl_802C9724, lbl_802C9780,
    lbl_802C97DC, lbl_802C983C, lbl_802C9898, lbl_802C98F8,
    lbl_802C9958, lbl_802C99B8, lbl_802C9A1C, lbl_802C9A7C,
    lbl_802C9ADC, lbl_802C9B3C, lbl_802C9B9C, lbl_802C9BFC,
    lbl_802C9C60, lbl_802C9CC0, lbl_802C9D20, lbl_802C9D80,
    lbl_802C9DE4, lbl_802C9E44, lbl_802C9EA4, lbl_802C9F04,
    lbl_802C9F64, lbl_802C9FC0, lbl_802CA01C, lbl_802CA078,
    lbl_802CA0D8, lbl_802CA13C, lbl_802CA19C, lbl_802CA1FC,
    lbl_802CA25C, lbl_802CA2BC, lbl_802CA320, lbl_802CA380,
    lbl_802CA3E0, lbl_802CA43C, lbl_802CA4A0, lbl_802CA500,
    lbl_802CA55C, lbl_802CA5BC, lbl_802CA618, lbl_802CA67C,
    lbl_802CA6DC, lbl_802CA740, lbl_802CA7A0, lbl_802CA800,
    lbl_802CA860, lbl_802CA8C0, lbl_802CA920, lbl_802CA980,
    lbl_802CA9E4, lbl_802CAA44, lbl_802CAAA4, lbl_802CAB08,
    lbl_802CAB64, lbl_802CABC0, lbl_802CAC1C, lbl_802CAC7C,
    lbl_802CACDC, lbl_802CAD3C,
};
const char *lbl_802F6A10[80] = {
    lbl_802CAD9C, lbl_802CADFC, lbl_802CAE5C, lbl_802CAEB4,
    lbl_802CAF0C, lbl_802CAF6C, lbl_802CAFCC, lbl_802CB02C,
    lbl_802CB08C, lbl_802CB0E4, lbl_802CB140, lbl_802CB19C,
    lbl_802CB1F8, lbl_802CB248, lbl_802CB294, lbl_802CB2F0,
    lbl_802CB350, lbl_802CB3A0, lbl_802CB3FC, lbl_802CB450,
    lbl_802CB4AC, lbl_802CB504, lbl_802CB564, lbl_802CB5C4,
    lbl_802CB620, lbl_802CB678, lbl_802CB6D8, lbl_802CB734,
    lbl_802CB790, lbl_802CB7F0, lbl_802CB848, lbl_802CB8A0,
    lbl_802CB900, lbl_802CB958, lbl_802CB9A8, lbl_802CB9E0,
    lbl_802CBA1C, lbl_802CBA68, lbl_802CBAAC, lbl_802CBAF0,
    lbl_802CBB3C, lbl_802CBB9C, lbl_802CBBF0, lbl_802CBC50,
    lbl_802CBCB0, lbl_802CBD10, lbl_802CBD68, lbl_802CBDBC,
    lbl_802CBE10, lbl_802CBE68, lbl_802CBEB8, lbl_802CBF08,
    lbl_802CBF68, lbl_802CBFB4, lbl_802CC014, lbl_802CC074,
    lbl_802CC0D0, lbl_802CC12C, lbl_802CC188, lbl_802CC1E0,
    lbl_802CC238, lbl_802CC288, lbl_802CC2E4, lbl_802CC33C,
    lbl_802CC398, lbl_802CC3EC, lbl_802CC44C, lbl_802CC4A4,
    lbl_802CC504, lbl_802CC558, lbl_802CC5B4, lbl_802CC608,
    lbl_802CC658, lbl_802CC6B0, lbl_802CC704, lbl_802CC704,
    lbl_802CC704, lbl_802CC704, lbl_802CC704, lbl_802CC704,
};
const char *lbl_802F6B50[80] = {
    lbl_802CC714, lbl_802CC74C, lbl_802CC78C, lbl_802CC7D4,
    lbl_802CC820, lbl_802CC870, lbl_802CC8CC, lbl_802CC90C,
    lbl_802CC944, lbl_802CC994, lbl_802CC9F0, lbl_802CCA34,
    lbl_802CCA78, lbl_802CCAC0, lbl_802CCB1C, lbl_802CCB70,
    lbl_802CCBA8, lbl_802CCC00, lbl_802CCC4C, lbl_802CCC80,
    lbl_802CCCD4, lbl_802CCD14, lbl_802CCD70, lbl_802CCDA8,
    lbl_802CCDF8, lbl_802CCE50, lbl_802CCEAC, lbl_802CCF08,
    lbl_802CCF60, lbl_802CCFBC, lbl_802CD008, lbl_802CD058,
    lbl_802CD0AC, lbl_802CD104, lbl_802CD148, lbl_802CD180,
    lbl_802CD1DC, lbl_802CD228, lbl_802CD274, lbl_802CD2B4,
    lbl_802CD304, lbl_802CD35C, lbl_802CD3AC, lbl_802CD3FC,
    lbl_802CD444, lbl_802CD480, lbl_802CD4D8, lbl_802CD514,
    lbl_802CD56C, lbl_802CD5A8, lbl_802CD5E8, lbl_802CD640,
    lbl_802CD688, lbl_802CD6D8, lbl_802CD70C, lbl_802CD754,
    lbl_802CD7AC, lbl_802CD7E4, lbl_802CD834, lbl_802CC704,
    lbl_802CC704, lbl_802CC704, lbl_802CC704, lbl_802CC704,
    lbl_802CC704, lbl_802CC704, lbl_802CC704, lbl_802CC704,
    lbl_802CC704, lbl_802CC704, lbl_802CC704, lbl_802CC704,
    lbl_802CC704, lbl_802CC704, lbl_802CC704, lbl_802CC704,
    lbl_802CC704, lbl_802CC704, lbl_802CC704, lbl_802CC704,
};
const char *lbl_802F6C90[80] = {
    lbl_802CD880, lbl_802CD8D4, lbl_802CD934, lbl_802CD988,
    lbl_802CD9CC, lbl_802CDA28, lbl_802CDA7C, lbl_802CDADC,
    lbl_802CDB30, lbl_802CDB74, lbl_802CDBCC, lbl_802CDC0C,
    lbl_802CDC5C, lbl_802CDCAC, lbl_802CDD00, lbl_802CDD4C,
    lbl_802CDDA4, lbl_802CDDEC, lbl_802CDE34, lbl_802CDE88,
    lbl_802CDEE0, lbl_802CDF3C, lbl_802CDF90, lbl_802CDFE8,
    lbl_802CE040, lbl_802CE07C, lbl_802CE0D0, lbl_802CE12C,
    lbl_802CE184, lbl_802CE1C4, lbl_802CE21C, lbl_802CE278,
    lbl_802CE2C8, lbl_802CE328, lbl_802CE374, lbl_802CE3C8,
    lbl_802CE414, lbl_802CE46C, lbl_802CE4B4, lbl_802CE510,
    lbl_802CE548, lbl_802CE5A4, lbl_802CE5D4, lbl_802CE620,
    lbl_802CE67C, lbl_802CE6C4, lbl_802CE708, lbl_802CE750,
    lbl_802CE7AC, lbl_802CE80C, lbl_802CE868, lbl_802CE8C0,
    lbl_802CE918, lbl_802CE974, lbl_802CE9C4, lbl_802CEA20,
    lbl_802CEA78, lbl_802CEACC, lbl_802CEB20, lbl_802CEB6C,
    lbl_802CEBAC, lbl_802CEBEC, lbl_802CEC30, lbl_802CC704,
    lbl_802CC704, lbl_802CC704, lbl_802CC704, lbl_802CC704,
    lbl_802CC704, lbl_802CC704, lbl_802CC704, lbl_802CC704,
    lbl_802CC704, lbl_802CC704, lbl_802CC704, lbl_802CC704,
    lbl_802CC704, lbl_802CC704, lbl_802CC704, lbl_802CC704,
};
const char *lbl_802F6DD0[80] = {
    lbl_802CEC88, lbl_802CECE0, lbl_802CED3C, lbl_802CED98,
    lbl_802CEDF0, lbl_802CEE40, lbl_802CEE8C, lbl_802CEED8,
    lbl_802CEF18, lbl_802CEF5C, lbl_802CEFB8, lbl_802CF01C,
    lbl_802CF058, lbl_802CF0A0, lbl_802CF0F0, lbl_802CF13C,
    lbl_802CF17C, lbl_802CF1B8, lbl_802CF1F0, lbl_802CF24C,
    lbl_802CF2AC, lbl_802CF304, lbl_802CF35C, lbl_802CF3B4,
    lbl_802CF414, lbl_802CF46C, lbl_802CF4C4, lbl_802CF51C,
    lbl_802CF57C, lbl_802CF5D0, lbl_802CF628, lbl_802CF680,
    lbl_802CF6D4, lbl_802CF728, lbl_802CF788, lbl_802CF7E0,
    lbl_802CF83C, lbl_802CF890, lbl_802CF8EC, lbl_802CF944,
    lbl_802CF99C, lbl_802CF9F0, lbl_802CFA44, lbl_802CFAA0,
    lbl_802CFAD8, lbl_802CFB10, lbl_802CFB6C, lbl_802CFBC4,
    lbl_802CFC04, lbl_802CFC60, lbl_802CFCA4, lbl_802CFCEC,
    lbl_802CFD40, lbl_802CFDA0, lbl_802CFDD8, lbl_802CFE2C,
    lbl_802CFE88, lbl_802CFEDC, lbl_802CFF30, lbl_802CFF84,
    lbl_802CFFC8, lbl_802CFFC8, lbl_802CC704, lbl_802CC704,
    lbl_802CC704, lbl_802D000C, lbl_802D0068, lbl_802D00A8,
    lbl_802D00F4, lbl_802D0148, lbl_802D0194, lbl_802D01F0,
    lbl_802D0250, lbl_802D02A8, lbl_802D0300, lbl_802D0354,
    lbl_802D03B0, lbl_802D03F8, lbl_802D0450, lbl_802D0498,
};
const char *lbl_802F6F10[80] = {
    lbl_802D04EC, lbl_802D0548, lbl_802D05A4, lbl_802D0600,
    lbl_802D065C, lbl_802D06B8, lbl_802D06C4, lbl_802D0718,
    lbl_802D0768, lbl_802D07BC, lbl_802D0818, lbl_802D0870,
    lbl_802D08CC, lbl_802D0924, lbl_802D097C, lbl_802D09D8,
    lbl_802D0A2C, lbl_802D0A84, lbl_802D06B8, lbl_802D0AE0,
    lbl_802D0B2C, lbl_802D0B70, lbl_802D0BC4, lbl_802D0C18,
    lbl_802D0C28, lbl_802D0C7C, lbl_802D0CD4, lbl_802D0C18,
    lbl_802D0D2C, lbl_802D0D88, lbl_802D0DEC, lbl_802D0E34,
    lbl_802D0E98, lbl_802D0E98, lbl_802D06B8, lbl_802D0EF0,
    lbl_802D0F44, lbl_802D0F98, lbl_802D0FF4, lbl_802D1054,
    lbl_802D10AC, lbl_802D1104, lbl_802D1164, lbl_802D11C4,
    lbl_802D11C4, lbl_802CC704, lbl_802CC704, lbl_802CC704,
    lbl_802CC704, lbl_802CC704, lbl_802CC704, lbl_802CC704,
    lbl_802CC704, lbl_802CC704, lbl_802CC704, lbl_802CC704,
    lbl_802CC704, lbl_802CC704, lbl_802CC704, lbl_802CC704,
    lbl_802CC704, lbl_802CC704, lbl_802CC704, lbl_802CC704,
    lbl_802CC704, lbl_802CC704, lbl_802CC704, lbl_802CC704,
    lbl_802CC704, lbl_802CC704, lbl_802CC704, lbl_802CC704,
    lbl_802CC704, lbl_802CC704, lbl_802CC704, lbl_802CC704,
    lbl_802CC704, lbl_802CC704, lbl_802CC704, lbl_802CC704,
};
const char *lbl_802F7050[40] = {
    lbl_802D1220, lbl_802D1278, lbl_802D12CC, lbl_802D1324,
    lbl_802D1380, lbl_802D13E0, lbl_802D142C, lbl_802D1488,
    lbl_802D14D4, lbl_802D1514, lbl_802D1568, lbl_802D15A0,
    lbl_802D15F4, lbl_802D1644, lbl_802D1694, lbl_802D16CC,
    lbl_802D1710, lbl_802D1760, lbl_802D179C, lbl_802D17E8,
    lbl_802D1844, lbl_802D18A4, lbl_802D1904, lbl_802D1960,
    lbl_802D19B4, lbl_802D1A00, lbl_802D1A54, lbl_802D1AB4,
    lbl_802D1B00, lbl_802D1B58, lbl_802D1BB8, lbl_802D1C00,
    lbl_802D1C60, lbl_802D1CA8, lbl_802D1CF8, lbl_802D1D40,
    lbl_802D1D94, lbl_802D1DEC, lbl_802D1E40, lbl_802D1E9C,
};
const char *lbl_802F70F0[40] = {
    lbl_802D1EF8, lbl_802D1F58, lbl_802D1FB8, lbl_802D2008,
    lbl_802D2058, lbl_802D20B0, lbl_802D20F0, lbl_802D2138,
    lbl_802D218C, lbl_802D21C8, lbl_802D21F4, lbl_802D2244,
    lbl_802D22A0, lbl_802D22FC, lbl_802D2338, lbl_802D2394,
    lbl_802D23E4, lbl_802D2434, lbl_802D2498, lbl_802D24EC,
    lbl_802D254C, lbl_802D2590, lbl_802D25D8, lbl_802D2638,
    lbl_802D2684, lbl_802D26DC, lbl_802D272C, lbl_802D278C,
    lbl_802D27E4, lbl_802D2840, lbl_802D2898, lbl_802D28EC,
    lbl_802D2938, lbl_802D2988, lbl_802D29E0, lbl_802D2A28,
    lbl_802D2A84, lbl_802D2ADC, lbl_802D2B38, lbl_802D2B90,
};
const char *lbl_802F7190[30] = {
    lbl_802D2BF0, lbl_802D2C20, lbl_802D2C74, lbl_802D2CC4,
    lbl_802D2D1C, lbl_802D2D74, lbl_802D2DD0, lbl_802D2E2C,
    lbl_802D2E88, lbl_802D2EE0, lbl_802D2F3C, lbl_802D2F80,
    lbl_802D2FC8, lbl_802D3024, lbl_802D306C, lbl_802D30B8,
    lbl_802D3108, lbl_802D3168, lbl_802D31C4, lbl_802D3220,
    lbl_802D3264, lbl_802D32AC, lbl_802D3308, lbl_802D3350,
    lbl_802D33B0, lbl_802D340C, lbl_802D3460, lbl_802D34AC,
    lbl_802D3508, lbl_802D3564,
};

void fn_801EF7E0(void);
typedef struct {
    u8 pad[0x2c];
    s8 bits[1];
} BitOwner;
s8 fn_801EF300(void);
u32 fn_801F4C24(s16 id);
s8 fn_801EFCC4(s16 id, s32 n);
extern const s8 lbl_802D4600[24];
s32 fn_801E4BBC(s8 i);
s32 fn_801F4A60(s16 id);
extern WeaponData lbl_802C5790[];
extern GearData lbl_802C6190[];
extern GearData lbl_802C6E10[];
extern ShipGearData lbl_802D83EC[];
extern s8 fn_801F452C(s16 id);

s32 fn_801F2508(void *a, void *b)
{
    return *(s16 *)((u8 *)a + 0xa) - *(s16 *)((u8 *)b + 0xa);
}

s32 fn_801F2894(s32 a, s32 b)
{
    StatRec *r = &lbl_8030B4D4.chr[a];
    return r->x60[b];
}

s32 fn_801F28B4(s32 a)
{
    StatRec *r = &lbl_8030B4D4.chr[a];
    return r->x18;
}

extern s8 lbl_802C9628[][4];
extern void fn_801EFFD8(s16 v);
extern void fn_801EFFFC(s16 v);

void fn_801F28CC(s32 code) {
    s32 next;
    s8 v;
    s32 cur;
    lbl_8030B7F4.xb4f = 0;
    next = -1;
    cur = lbl_8030B7F4.x32e;
    if (lbl_8030B7F4.x32f >= 3 && lbl_8030B7F4.x330 >= 30) {
        lbl_8030B7F4.xb4f = 2;
        next = 0x2f;
    } else if (code == 0x103) {
        s8* t = lbl_802C9628[cur - 0x20];
        if (t[0] <= lbl_8030B7F4.x330) {
            v = t[1];
            if (v != -1) {
                lbl_8030B7F4.xb4f = 1;
                next = v + 0x20;
            }
        }
    } else {
        s8* t = lbl_802C9628[cur - 0x20];
        v = t[3];
        if (v != -1) {
            lbl_8030B7F4.xb4f = 1;
            next = v + 0x20;
        }
    }
    if (next != -1) {
        lbl_8030B7F4.x32e = next;
        fn_801EFFD8(cur);
        fn_801EFFFC(next);
        lbl_8030B7F4.chr[2].slot0 = next;
    }
    lbl_8030B7F4.xb50 &= ~0x40;
    if (lbl_802C9628[next - 0x20][1] != lbl_802C9628[next - 0x20][3]) {
        lbl_8030B7F4.xb50 |= 0x40;
    }
}

extern u32 lbl_80310B3C[];

typedef struct LvPair {
    s8 id;
    s8 lv;
} LvPair;

/* The block lbl_803474D8 points at (lbl_80313B20, set in evobj.c): (id, level) pairs at 0xB40. */
typedef struct EvTbl {
    u8 pad0[0xb40];
    LvPair pairs[0x3c - 0x24]; /* 0xB40 */
} EvTbl;

extern EvTbl *lbl_803474D8;

void fn_801F2E44(s32 id)
{
    s8 i;
    SaveChar *e;
    LvPair *t;

    t = lbl_803474D8->pairs;
    e = &lbl_8030B7F4.chr[id];
    i = 0x24;
    do {
        s8 a = t->id;
        s8 b = t->lv;
        t++;
        if (a == id && b <= e->lvMax) {
            e->stat[i / 8] |= 1 << (i % 8);
        }
        i++;
    } while (i < 0x3c);
}

void fn_801F2A34(s32 n, s32 v);
void fn_801F2ED4(s32 a, s32 b, s32 val);
static inline void Reset2(SaveChar *r, SaveChar *r2, s32 n, s32 i)
{
    s32 v = r2->x44[i];
    r->x44[i] = 0;
    fn_801F2ED4(n, i, 0);
    fn_801F2ED4(n, i, v);
}
static inline void Reset1(SaveChar *c, s32 n)
{
    s32 old = c->x24;
    c->x24 = 0;
    fn_801F2A34(n, 0);
    fn_801F2A34(n, old);
}
void fn_801F3024(s32 n)
{
    s32 i;
    SaveChar *r2 = &lbl_8030B7F4.chr[n];
    SaveChar *r = &lbl_8030B7F4.chr[n];
    LvPair *p;
    s8 j;
    Reset1(r, n);
    for (i = 0; i < 6; i++) {
        Reset2(r, r2, n, i);
    }
    p = lbl_803474D8->pairs;
    j = 0x24;
    do {
        s8 a = p->id;
        s8 b = p->lv;
        p++;
        if (a == n && b <= r->lvMax) {
            r->stat[j / 8] |= 1 << (j % 8);
        }
        j++;
    } while (j < 0x3c);
}

void fn_801EFF90(s16 id);
void fn_801EFF48(s16 id);

s32 fn_801F3844(s32 idx)
{
    SaveChar *c;
    s32 i;
    u32 b, d;
    b = idx + 0x408;
    d = idx + 0x402;
    lbl_80310B3C[b >> 5] &= ~(1 << (b & 31));
    lbl_80310B3C[d >> 5] |= 1 << (d & 31);
    c = &lbl_8030B7F4.chr[idx];
    for (i = 0; i < 4; i++) {
        if (lbl_8030B7F4.party[i] == idx) {
            for (; i < 3; i++) {
                lbl_8030B7F4.party[i] = lbl_8030B7F4.party[i + 1];
            }
            lbl_8030B7F4.party[i] = -1;
            lbl_8030B4D4.x2d4--;
            fn_801EFFD8(c->slot0);
            fn_801EFF90(c->slot1);
            fn_801EFF48(c->slot2);
            fn_801EF7E0();
            if (idx == 2) {
                lbl_8030B7F4.xb50 &= ~4;
            }
            return 1;
        }
    }
    return 0;
}

s32 fn_801F39EC(s32 idx) {
    SaveChar* c;
    s32 i;
    u32 b, d;
    b = idx + 0x408;
    d = idx + 0x402;
    lbl_80310B3C[b >> 5] &= ~(1 << (b & 31));
    lbl_80310B3C[d >> 5] |= 1 << (d & 31);
    c = &lbl_8030B7F4.chr[idx];
    for (i = 0; i < 4; i++) {
        if (lbl_8030B7F4.party[i] == idx) {
            for (; i < 3; i++) {
                lbl_8030B7F4.party[i] = lbl_8030B7F4.party[i + 1];
            }
            lbl_8030B7F4.party[i] = -1;
            lbl_8030B4D4.x2d4--;
            fn_801EFFD8(c->slot0);
            c->slot1 = -1;
            c->slot2 = -1;
            fn_801EF7E0();
            if (idx == 2) {
                lbl_8030B7F4.xb50 &= ~4;
            }
            return 1;
        }
    }
    return 0;
}

void fn_801F4E04(s32 i, s16 v) {
    SaveChar *p = lbl_8030B7F4.chr;
    p += i;
    p->slot2 = v;
    fn_801EF7E0();
}

void fn_801F4E38(s32 i, s16 v) {
    SaveChar *p = lbl_8030B7F4.chr;
    p += i;
    p->slot1 = v;
    fn_801EF7E0();
}

void fn_801F4E6C(s32 i, s16 v) {
    SaveChar *p = lbl_8030B7F4.chr;
    p += i;
    p->slot0 = v;
    fn_801EF7E0();
}

s32 fn_801F3F88(BitOwner *p, s8 i)
{
    return (p->bits[i / 8] & (1 << (i % 8))) != 0;
}

PirateRank *fn_801F2860(void) {
    s8 i;

    i = fn_801EF300();
    return &lbl_802C8E54[i];
}

s32 fn_801F49DC(s16 id) {
    u32 k;

    k = fn_801F4C24(id);
    switch (k) {
    case 0:
        return 0x0;
    case 1:
        return 0x50;
    case 2:
        return 0xa0;
    case 3:
        return 0xf0;
    case 4:
        return 0x140;
    case 5:
        return 0x190;
    case 6:
        return 0x1b8;
    case 7:
        return 0x1e0;
    default:
        return 0x0;
    }
}

s32 fn_801F4A60(s16 id) {
    u32 k;

    k = fn_801F4C24(id);
    switch (k) {
    case 0:
        return 0x50;
    case 1:
        return 0x50;
    case 2:
        return 0x50;
    case 3:
        return 0x50;
    case 4:
        return 0x50;
    case 5:
        return 0x28;
    case 6:
        return 0x28;
    case 7:
        return 0x1e;
    default:
        return 0x0;
    }
}

u32 fn_801F4C24(s16 id)
{
    u32 k;
    if (id < 0x50) k = 0;
    else if (id < 0xa0) k = 1;
    else if (id < 0xf0) k = 2;
    else if (id < 0x140) k = 3;
    else if (id < 0x190) k = 4;
    else if (id < 0x1b8) k = 5;
    else if (id < 0x1e0) k = 6;
    else k = 7;
    return k;
}

s8 fn_801F4CA0(void) {
    s32 i;
    s8 mask;

    mask = 0;
    for (i = 0; i < 6; i++) {
        if (fn_801EFCC4(0x146 + i, 4)) {
            mask = (s8)(mask | (1 << i));
        }
    }
    return mask;
}

s32 fn_801F464C(s16 id)
{
    switch (fn_801F4C24(id)) {
    case 0:
        return lbl_802C5790[id].can_sell;
    case 1:
        return lbl_802C6190[id - 80].can_sell;
    case 2:
        return lbl_802C6E10[id - 160].can_sell;
    case 3:
        return lbl_802C7C34[id - 240].can_sell;
    case 4:
        return lbl_802C8774[id - 320].can_sell;
    case 5:
        return lbl_802D7E4C[id - 400].can_sell;
    case 6:
        return lbl_802D83EC[id - 440].can_sell;
    case 7:
        return lbl_802D8A2C[id - 480].can_sell;
    default:
        return 0;
    }
}

extern u32 lbl_80310B3C[];
extern void fn_801EFFFC(s16 id);
extern void fn_801EFFB4(s16 id);
extern void fn_801EFF6C(s16 id);
extern void fn_801EFFD8(s16 id);
extern void fn_801EFF90(s16 id);
extern void fn_801EFF48(s16 id);
extern s32 fn_801F3B90(s32 i);

s32 fn_801F3E6C(s32 i) {
    SaveChar *c;
    CharParam *r;
    u32 f1 = i + 0x408;
    u32 f2 = i + 0x402;
    lbl_80310B3C[f1 >> 5] |= 1 << (f1 & 31);
    lbl_80310B3C[f2 >> 5] |= 1 << (f2 & 31);
    c = &lbl_8030B7F4.chr[i];
    r = &lbl_802C4860[i];
    fn_801EFFFC(r->weapon);
    c->slot0 = r->weapon;
    fn_801EFFB4(r->armor);
    c->slot1 = r->armor;
    fn_801EFF6C(r->acc);
    c->slot2 = r->acc;
    if (fn_801F3B90(i) != 0) {
        if (i == 2) {
            lbl_8030B7F4.xb50 |= 4;
        }
        return 1;
    }
    fn_801EFFD8(r->weapon);
    fn_801EFF90(r->armor);
    fn_801EFF48(r->acc);
    return 0;
}

s32 fn_801F4D14(void)
{
    s32 i;
    s32 sb = 0;
    s32 sa = 0;
    for (i = 0; i < 5; i++) {
        s8 k = lbl_8030B7F4.party[i];
        if (k != -1) {
            SaveChar* e = &lbl_8030B7F4.chr[k];
            s32 a, b;
            b = e->hpMax;
            a = e->hp;
            if ((f32)a / (f32)b < 0.25f) {
                return 0;
            }
            sb += b;
            sa += a;
        }
    }
    return !((f32)sa / (f32)sb < 0.63);
}

s32 fn_801F4F54(s16* pa, s16* pb) {
    u8 ka;
    s16 a = *pa;
    s16 b = *pb;
    u8 kb;
    if (a == -1 && b == -1) return 0;
    if (a == -1) return 1;
    if (b == -1) return -1;
    switch (fn_801F4C24(a)) {
    case 0:
        ka = lbl_802C5790[a].sort2;
        kb = lbl_802C5790[b].sort2;
        break;
    case 1:
        ka = lbl_802C6190[a - 0x50].sort2;
        kb = lbl_802C6190[b - 0x50].sort2;
        break;
    case 2:
        ka = lbl_802C6E10[a - 0xa0].sort2;
        kb = lbl_802C6E10[b - 0xa0].sort2;
        break;
    case 3:
        ka = lbl_802C7C34[a - 0xf0].sort2;
        kb = lbl_802C7C34[b - 0xf0].sort2;
        break;
    case 4:
        ka = lbl_802C8774[a - 0x140].sort2;
        kb = lbl_802C8774[b - 0x140].sort2;
        break;
    case 5:
        ka = lbl_802D7E4C[a - 0x190].sort2;
        kb = lbl_802D7E4C[b - 0x190].sort2;
        break;
    case 6:
        ka = lbl_802D83EC[a - 0x1b8].sort2;
        kb = lbl_802D83EC[b - 0x1b8].sort2;
        break;
    case 7:
        ka = lbl_802D8A2C[a - 0x1e0].sort2;
        kb = lbl_802D8A2C[b - 0x1e0].sort2;
        break;
    }
    return ka - kb;
}

s32 fn_801F5100(s16 *a, s16 *b);
s32 fn_801F4F54(s16 *a, s16 *b);
#ifdef NONMATCHING
/* Exact only with the comparator held in a void *: the real qsort prototype wants const void * parameters, and comparators written that way do not match. */
void fn_801F4EA0(s32 kind, s32 byId)
{
    s16 count[8] = { 0x50, 0x50, 0x50, 0x50, 0x50, 0x28, 0x28, 0x1e };
    s16 start[8] = { 0x0, 0x50, 0xa0, 0xf0, 0x140, 0x1ae, 0x1d6, 0x190 };
    void *cmp;
    InvEnt *inv;
    if (byId & 1) cmp = fn_801F5100; else cmp = fn_801F4F54;
    inv = lbl_8030B7F4.s354;
    inv += start[kind];
    qsort(inv, count[kind], 4, cmp);
}
#endif

s32 fn_801F52AC(void)
{
    s8 i;
    s32 cnt;

    cnt = 0;
    for (i = 0; i < 0x16; i++) {
        if (fn_801E4BBC(i) != 0) {
            if (lbl_802D4600[i] == 0) {
                cnt += 1;
            } else {
                cnt += 0x100;
            }
        }
    }
    return cnt;
}

const void* fn_801F4AE4(s16 id) {
    if (id == -1) return 0;
    switch (fn_801F4C24(id)) {
    case 0: return &lbl_802C5790[id];
    case 1: return &lbl_802C6190[id - 0x50];
    case 2: return &lbl_802C6E10[id - 0xa0];
    case 3: return &lbl_802C7C34[id - 0xf0];
    case 4: return &lbl_802C8774[id - 0x140];
    case 5: return &lbl_802D7E4C[id - 0x190];
    case 6: return &lbl_802D83EC[id - 0x1b8];
    case 7: return &lbl_802D8A2C[id - 0x1e0];
    }
    return 0;
}

s32 fn_801F5100(s16 *a, s16 *b)
{
    u8 p;
    s16 x = *a;
    s16 y = *b;
    u8 q;
    if (x == -1 && y == -1) return 0;
    if (x == -1) return 1;
    if (y == -1) return -1;
    switch (fn_801F4C24(x)) {
    case 0: p = lbl_802C5790[x].sort; q = lbl_802C5790[y].sort; break;
    case 1: p = lbl_802C6190[x - 0x50].sort; q = lbl_802C6190[y - 0x50].sort; break;
    case 2: p = lbl_802C6E10[x - 0xa0].sort; q = lbl_802C6E10[y - 0xa0].sort; break;
    case 3: p = lbl_802C7C34[x - 0xf0].sort; q = lbl_802C7C34[y - 0xf0].sort; break;
    case 4: p = lbl_802C8774[x - 0x140].sort; q = lbl_802C8774[y - 0x140].sort; break;
    case 5: p = lbl_802D7E4C[x - 0x190].sort; q = lbl_802D7E4C[y - 0x190].sort; break;
    case 6: p = lbl_802D83EC[x - 0x1b8].sort; q = lbl_802D83EC[y - 0x1b8].sort; break;
    case 7: p = lbl_802D8A2C[x - 0x1e0].sort; q = lbl_802D8A2C[y - 0x1e0].sort; break;
    }
    return p - q;
}

u16 fn_801F477C(s16 id)
{
    switch (fn_801F4C24(id)) {
    case 0:
        return lbl_802C5790[id].price;
    case 1:
        return lbl_802C6190[id - 80].price;
    case 2:
        return lbl_802C6E10[id - 160].price;
    case 3:
        return lbl_802C7C34[id - 240].price;
    case 4:
        return lbl_802C8774[id - 320].price;
    case 5:
        return lbl_802D7E4C[id - 400].price;
    case 6:
        return lbl_802D83EC[id - 440].price;
    case 7:
        return lbl_802D8A2C[id - 480].price;
    default:
        return 0;
    }
}

const char *fn_801F48AC(s16 id) {
    if (id == -1) return 0;
    switch (fn_801F4C24(id)) {
    case 0:
        return lbl_802F6A10[id];
    case 1:
        return lbl_802F6B50[id - 80];
    case 2:
        return lbl_802F6C90[id - 160];
    case 3:
        return lbl_802F6DD0[id - 240];
    case 4:
        return lbl_802F6F10[id - 320];
    case 5:
        return lbl_802F7050[id - 400];
    case 6:
        return lbl_802F70F0[id - 440];
    case 7:
        return lbl_802F7190[id - 480];
    default:
        return 0;
    }
}

s8 fn_801F452C(s16 id) {
    s8 n = fn_801F4A60(id);
    InvEnt *tbl;
    InvEnt *e;
    s32 i;

    switch (fn_801F4C24(id)) {
    case 0:
        tbl = lbl_8030B7F4.s354;
        break;
    case 1:
        tbl = lbl_8030B7F4.s494;
        break;
    case 2:
        tbl = lbl_8030B7F4.s5d4;
        break;
    case 3:
        tbl = lbl_8030B7F4.s714;
        break;
    case 4:
        tbl = lbl_8030B7F4.s854;
        break;
    case 5:
        tbl = lbl_8030B7F4.sa0c;
        break;
    case 6:
        tbl = lbl_8030B7F4.saac;
        break;
    case 7:
        tbl = lbl_8030B7F4.s994;
        break;
    }
    e = tbl;
    i = 0;
    do {
        if (id == e->id) {
            return tbl[i].cnt;
        }
        i++;
        e++;
    } while (i < n);
    return 0;
}

#ifdef NONMATCHING
#endif

/* Whether character chr can equip item id: 0 no, 1 every copy is equipped by someone else, 2 yes. */
#ifdef NONMATCHING
s32 fn_801F3FD0(s32 chr, s16 id)
{
    s32 bit;
    u32 kind;
    s8 n;
    s32 ship;
    s32 i;
    s32 p;
    s16 k;

    bit = 5 - chr;
    kind = fn_801F4C24(id);
    n = fn_801F452C(id);
    ship = lbl_8030B7F4.x1568.b1568;
    switch (kind) {
    case 0:
        if (chr == lbl_802C5790[id].owner) {
            return 2;
        }
        break;
    case 1:
        k = id - 0x50;
        if ((1 << bit) & lbl_802C6190[k].owners) {
            for (i = 0; i < 4; i++) {
                p = lbl_8030B7F4.party[i];
                if (id == lbl_8030B7F4.chr[p].slot1 && chr != p) {
                    if (--n <= 0) {
                        return 1;
                    }
                }
            }
            return 2;
        }
        break;
    case 2:
        k = id - 0xa0;
        if ((1 << bit) & lbl_802C6E10[k].owners) {
            for (i = 0; i < 4; i++) {
                p = lbl_8030B7F4.party[i];
                if (id == lbl_8030B7F4.chr[p].slot2 && chr != p) {
                    if (--n <= 0) {
                        return 1;
                    }
                }
            }
            return 2;
        }
        break;
    case 5:
        if (ship == -1) {
            return 0;
        }
        k = id - 0x190;
        p = ((1 << (5 - ship)) & lbl_802D7E4C[k].ships) != 0;
        if (p) {
            if (chr == 4) {
                if (lbl_802D7E4C[k].type == 3) {
                    return 1;
                }
            } else if (lbl_802D7E4C[k].type != 3) {
                for (i = 0; i < 5; i++) {
                    if (lbl_8030B7F4.x1568.s1580[i] == id && chr != i) {
                        if (--n <= 0) {
                            return 1;
                        }
                    }
                }
                return 2;
            }
        }
        break;
    case 6:
        if (ship == -1) {
            return 0;
        }
        k = id - 0x1b8;
        if ((1 << (5 - ship)) & lbl_802D83EC[k].ships) {
            for (i = 0; i < 3; i++) {
                if (lbl_8030B7F4.x1568.s158a[i] == id && chr != i) {
                    if (--n <= 0) {
                        return 1;
                    }
                }
            }
            return 2;
        }
        break;
    }
    return 0;
}
#endif

s32 fn_801F3B90(s32 id) {
    s32 k;
    s32 j;
    s8 *p;
    s32 i;
    p = lbl_8030B7F4.party;
    for (i = 0; i < 4; i++) {
        if (lbl_8030B7F4.party[i] == id) {
            return 0;
        }
        if (lbl_8030B7F4.party[i] == -1) {
            p[i] = id;
            lbl_8030B4D4.x2d4 = lbl_8030B4D4.x2d4 + 1;
            for (k = 0; k < 4; k++) {
                for (j = 0; j < 3; j++) {
                    s8 *x;
                    s8 b;
                    s8 *y;
                    s8 a;
                    x = &p[j];
                    y = x + 1;
                    a = *x;
                    b = *y;
                    if (b != -1 && a > b) {
                        *x = b;
                        *y = a;
                    }
                }
            }
            fn_801EF7E0();
            return 1;
        }
    }
    return 0;
}
