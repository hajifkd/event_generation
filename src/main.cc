#include <iostream>
#include <cmath>
#include <string>
#include "Pythia8/Pythia.h"

using Pythia8::Pythia;

int main(int, char** argv) {
  Pythia pythia;
  std::string energy = std::string("Beams:eCM = ") + argv[1];
  pythia.readString(energy);
  pythia.readString("SoftQCD:all = on");
  pythia.init();

  for (int iEvent = 0; iEvent < 10000; ++iEvent) {
    if (!pythia.next()) continue;

    std::cerr << pythia.event.size() << std::endl;

    for (int i = 0; i < pythia.event.size(); i++) {
      auto& particle = pythia.event[i];
      if (particle.isFinal() && particle.isHadron() && particle.charge() != 0) {
        // Maybe we should reject too High pz, otherwise it would be the end-cap region
        std::cerr << particle.pT() << "," << particle.pz() << std::endl;
      }
    }

    std::cerr << std::endl;
  }

  return 0;
}
