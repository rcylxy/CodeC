#include <stdio.h>
#include <stdlib.h>
int main()
{
  int niu;
  int hou;
  int ji;
  int tu;
  int yang;
  int gou;
  int zhu;
  for (niu = 0; niu < 10; ++niu)
    for (hou = 0; niu < 10; ++niu)
      for (ji = 0; ji < 10; ++ji)
        for (tu = 1; tu < 10; ++tu)
          for (yang = 0; yang < 10; ++yang)
            for (gou = 0; gou < 10; ++gou)
              for (zhu = 1; zhu < 10; ++zhu)
              {
                if ((10 * zhu + hou + zhu == zhu * 11) && (10 * zhu + hou - ji == niu) && (ji / tu == tu) && (niu + yang == gou))
                {
                  printf("已找到\n");
                  printf("niu=%d\nhou=%d\nji=%d\ntu=%d\nyang=%d\ngou=%d\nzhu=%d\n", niu, hou, ji, tu, yang, gou, zhu);
                  return 0;
                }
              }
  printf("没找到");
  return -1;
}