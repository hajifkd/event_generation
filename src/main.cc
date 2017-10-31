#include <iostream>
#include "Pythia8/Pythia.h"

using Pythia8::Pythia;
using Pythia8::Hist;

int main() {
  Pythia pythia;
  pythia.readString("Beams:eCM = 13000.");
  pythia.readString("HardQCD:all = on");
  pythia.readString("PhaseSpace:pTHatMin = 200.");
  pythia.init();

  Hist mult("charged multiplicity", 100, -0.5, 799.5);

  // Begin event loop. Generate event. Skip if error. List first one.
  for (int iEvent = 0; iEvent < 1; ++iEvent) {
    if (!pythia.next()) continue;

    // Find number of all final charged particles and fill histogram.
    int nCharged = 0;
    for (int i = 0; i < pythia.event.size(); ++i) {
      if (pythia.event[i].isFinal() && pythia.event[i].isHadron()) {
        std::cout << pythia.event[i].pT() << std::endl;
      }
    }
    // mult.fill( nCharged );
    // End of event loop. Statistics. Histogram. Done.
  }
  pythia.stat();

  return 0;
}
