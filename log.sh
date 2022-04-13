#!/bin/bash

pmset displaysleepnow

sleep 5s

osascript -e 'tell application "System Events" to key code 123'

