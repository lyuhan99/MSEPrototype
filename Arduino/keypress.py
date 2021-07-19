import keyboard
import time
while True:
    if keyboard.is_pressed("a"):
        print("a is pressed")
        time.sleep(0.2)
        continue
    if keyboard.is_pressed("b"):
        print("b is pressed")
        time.sleep(0.2)
        continue
    if keyboard.is_pressed("c"):
        print("c is pressed")
        time.sleep(0.2)
        continue
    if keyboard.is_pressed("d"):
        print("d is pressed")
        time.sleep(0.2)
        continue
    if keyboard.is_pressed("up"):
        print("up is pressed")
        time.sleep(0.2)
        continue
    if keyboard.is_pressed("down"):
        print("down is pressed")
        time.sleep(0.2)
        continue
    if keyboard.is_pressed("left"):
        print("left is pressed")
        time.sleep(0.2)
        continue
    if keyboard.is_pressed("right"):
        print("right is pressed")
        time.sleep(0.2)
        continue


    if keyboard.is_pressed("q"):
        break
