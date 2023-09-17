import serial
import time

arduino = serial.Serial('/dev/ttyUSB0',9600)
#1 do nothing
#2 rotate clockwise
#3 rotate anticlockwise
#4 fire
#5 end fire


import cv2

# Load the cascade
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

# To capture video from webcam. 
cap = cv2.VideoCapture(0)
firing = False
rectangle_colour = (255, 0, 0)
fireLength = 6.5

while True:
    # Read the frame
    _, img = cap.read()
    # Convert to grayscale
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    # Detect the faces
    faces = face_cascade.detectMultiScale(gray, 1.1, 6)
    imgw = img.shape[1]
    line_thickness = 2
    cv2.line(img, (int(imgw/2), 0), (int(imgw/2), img.shape[0]), (0, 255, 0), thickness=line_thickness)
    if len(faces)>0:
        (x, y, w, h) = faces[0]
        cv2.rectangle(img, (x, y), (x+w, y+h), rectangle_colour, 2)
        if x+w < imgw/2:
            print(3)
            arduino.write(b'3')
            time.sleep(.2)
        else:
            if x > imgw/2:
                print(2)
                arduino.write(b'2')
                time.sleep(.2)
        if x < imgw/2 and x+w>imgw/2 and not firing:
            print(4)
            arduino.write(b'4')
            firing = True
            rectangle_colour = (0, 0, 255)
            startTime = time.time()
    # Display
    cv2.imshow('img', img)
    # Stop if escape key is pressed
    k = cv2.waitKey(30) & 0xff
    if k==27:
        break
    if firing:
        if time.time()-startTime>fireLength:
            print(5)
            arduino.write(b'5')
            break
# Release the VideoCapture object
cap.release()
arduino.close()