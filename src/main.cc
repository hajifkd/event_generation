#include <iostream>
#include "Pythia8/Pythia.h"

using Pythia8::Pythia;
using Pythia8::Hist;

int main() {
  Pythia pythia;
  pythia.readString("Beams:eCM = 13000.");
  pythia.readString("SoftQCD:all = on");
  pythia.readString("PhaseSpace:pTHatMin = 200.");
  pythia.init();

  Hist mult("charged multiplicity", 100, -0.5, 799.5);

  for (int iEvent = 0; iEvent < 1; ++iEvent) {
    if (!pythia.next()) continue;

    int nCharged = 0;
    for (int i = 0; i < pythia.event.size(); ++i) {
      if (pythia.event[i].isFinal() && pythia.event[i].isHadron()) {
        std::cout << pythia.event[i].pT() << std::endl;
      }
    }
  }
  pythia.stat();

  return 0;
}
