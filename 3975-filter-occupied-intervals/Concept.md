# Sorting by end time is used for Greedy Interval Scheduling (often called Activity Selection).

1- Use Start Time when: You want to group, merge, or find overlaps (e.g., "Combine all overlapping meetings").

2- Use End Time when: You want to find the maximum number of non-overlapping intervals you can fit into a timeline (e.g., "I have 10 meetings today; what is the maximum number of meetings I can attend without double-booking?"). Sorting by end time allows you to greedily pick the meeting that finishes the fastest, freeing you up for the next one.
