#!/bin/bash

for ((i = 0; i <= 10000000; i++)); do
  echo "Running test case: $i"
  
  ./gen $i > int
  
  # Run the solution and catch runtime errors
  ./sol < int
  exit_code=$?

  if [[ $exit_code -ne 0 ]]; then
    echo "Error encountered on test case: $i"
    echo "Exit code: $exit_code"
    break
  fi

  # Optional delay
done

