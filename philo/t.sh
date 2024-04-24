#!/bin/bash

# Function to measure time slept
measure_sleep() {
    start_time=$(date +%s.%N)
    usleep $1
    end_time=$(date +%s.%N)
    duration=$(echo "$end_time - $start_time" | bc)
    echo "Slept for: $duration seconds"
}

# Start with a small usleep duration, e.g., 100 microseconds
usleep_duration=100

# Measure the time slept for the specified duration
measure_sleep $usleep_duration
