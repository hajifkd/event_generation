import matplotlib.pyplot as plt
import sys

def read_data():
    events = []

    with open(sys.argv[1]) as f:
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

    barrel = [len([0 for [pt, pz] in d if pt > 0.1 and abs(pz / pt) < 2.5]) for d in data]

    plt.hist(barrel, bins=100, range=(1, 200))
    plt.xticks(list(range(0, 200, 20)))
    plt.show()

if __name__ == "__main__":
    main()
