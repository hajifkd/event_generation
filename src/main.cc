#include <iostream>
#include "Pythia8/Pythia.h"

using Pythia8::Pythia;

int main() {
  Pythia pythia;
  pythia.readString("Beams:eCM = 14000.");
  pythia.readString("SoftQCD:all = on");
  pythia.init();

  for (int iEvent = 0; iEvent < 1; ++iEvent) {
    if (!pythia.next()) continue;

    std::cerr << pythia.event.size() << std::endl;

    for (int i = 0; i < pythia.event.size(); i++) {
      if (pythia.event[i].isFinal() && pythia.event[i].isHadron()) {
        // Maybe we should reject too High pz, otherwise it would be the end-cap region
        std::cerr << pythia.event[i].pT() << "," << pythia.event[i].pz() << std::endl;
      }
    }

    // We need information for the number of the jets in one vertex, maybe
    std::cerr << std::endl;
  }

  return 0;
}
