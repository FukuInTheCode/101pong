#!/bin/bash

range=$1

# Test command with arguments in a certain range
for x0 in $(seq -$range $range)
do
    for y0 in $(seq -$range $range)
    do
        for z0 in $(seq -$range $range)
        do
            for x1 in $(seq -$range $range)
            do
                for y1 in $(seq -$range $range)
                do
                    for z1 in $(seq -$range $range)
                    do
                        for n in $(seq -$range $range)
                        do
                            output=$(../101pong $x0 $y0 $z0 $x1 $y1 $z1 $n | tail -0 && echo $?)
                            if [ $output -eq 84 ]; then
                                echo "Test failed with arguments: $x0 $y0 $z0 $x1 $y1 $z1 $n"
                            fi
                        done
                    done
                done
            done
        done
    done
done
