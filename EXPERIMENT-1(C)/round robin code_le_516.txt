def main():
    n = int(input("Enter the number of processes: "))
    bu = [0] * n
    wa = [0] * n
    tat = [0] * n
    ct = [0] * n
    awt = 0
    att = 0
    temp = 0

    for i in range(n):
        bu[i] = int(input(f"Enter Burst Time for process {i+1}: "))
        ct[i] = bu[i]

    t = int(input("\nEnter the size of time slice: "))
    max_burst = max(bu)

    for j in range((max_burst // t) + 1):
        for i in range(n):
            if bu[i] != 0:
                if bu[i] <= t:
                    tat[i] = int(temp + bu[i])
                    temp += bu[i]
                    bu[i] = 0
                else:
                    bu[i] -= t
                    temp += t

    for i in range(n):
        wa[i] = tat[i] - ct[i]
        att += tat[i]
        awt += wa[i]

    print(f"\nThe Average Turnaround time is: {att / n:.2f}")
    print(f"The Average Waiting time is: {awt / n:.2f}")
    print("\n\tPROCESS\t BURST TIME \t WAITING TIME\tTURNAROUND TIME")
    for i in range(n):
        print(f"\t{i+1} \t {ct[i]} \t\t {wa[i]} \t\t {tat[i]}")

if __name__ == "__main__":
    main()
