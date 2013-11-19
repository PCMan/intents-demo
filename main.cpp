#include <QtGui/QApplication>
#include "intentsdialog.h"

int main(int argc, char** argv)
{
  QApplication app(argc, argv);
  if(argc < 2)
    return 1;
  IntentsDialog dlg(argv[1]);
  dlg.exec();
  return 0;
}
