import matplotlib.pyplot as plt

def read_data():
    events = []

    with open("pTpZ13TeV.dat") as f:
        while True:
            line = f.readline().strip()
            if not line:
                break

            line = int(line)
            event = []
            for i in range(line):
                ptpz = f.readline().strip()

                if not ptpz:
                    break

                event.append([float(d) for d in ptpz.split(',')])

            events.append(event)

    return events

def main():
    data = read_data()

    barrel = [len([0 for [pt, pz] in d if pt > 0.5 and abs(pz) / pt < 2.5]) for d in data]

    plt.hist(barrel)
    plt.show()

if __name__ == "__main__":
    main()
