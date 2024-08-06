def main():
    p = [0] * 20
    bt = [0] * 20
    pri = [0] * 20
    wt = [0] * 20
    tat = [0] * 20
    wtavg = 0
    tatavg = 0

    n = int(input("Enter the number of processes: "))

    for i in range(n):
        p[i] = i
        print(f"Enter the Burst Time & Priority of Process {i}: ", end="")
        bt[i] = int(input().split()[0])
        pri[i] = int(input())

    for i in range(n):
        for k in range(i + 1, n):
            if pri[i] > pri[k]:
                p[i], p[k] = p[k], p[i]
                bt[i], bt[k] = bt[k], bt[i]
                pri[i], pri[k] = pri[k], pri[i]

    wt[0] = 0
    tat[0] = bt[0]

    for i in range(1, n):
        wt[i] = wt[i - 1] + bt[i - 1]
        tat[i] = tat[i - 1] + bt[i]
        wtavg += wt[i]
        tatavg += tat[i]

    print("\nPROCESS\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME")
    for i in range(n):
        print(f"{p[i]}\t{pri[i]}\t{bt[i]}\t{wt[i]}\t{tat[i]}")
    print(f"Average Waiting Time is: {wtavg / n}")
    print(f"Average Turnaround Time is: {tatavg / n}")

if __name__ == "__main__":
    main()
