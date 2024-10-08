#ifndef CARMERA_H
#define CARMERA_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>
#include <iostream>

// defines several possible options for carmera movement.Used as abstraction to stay away from window-system specific input methods
enum Camera_Movement{
    FORWARD,
    BACKWARD, 
    LEFT,
    RIGHT, 
    UP,
    DOWN,
    PITCHUP,
    PITCHDOWN,
    YAWUP,
    YAWDOWN
};

// default camera values
const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.05f;
const float ZOOM = 45.0f;

class Camera {
public:
    // camera attributes
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;
    glm::vec3 Right;
    glm::vec3 WorldUp;
    // eular angles
    // float Roll;
    float Yaw;
    float Pitch;
    // camera options
    float MovementSpeed;
    float MouseSensitivity;
    float Zoom;
    // constructor with vectors
    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH)
        : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM) {
            Position = position;
            WorldUp = up;
            Yaw = yaw;
            Pitch = pitch;
            updateCameraVectors();
    }
    Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch)
        : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM) {
            Position = glm::vec3(posX, posY, posZ);
            WorldUp = glm::vec3(upX, upY, upZ);
            Yaw = yaw;
            Pitch = pitch;
            updateCameraVectors();
    }
    // returns the view matrix calculated using Eular angles and the LookAt Matrix
    glm::mat4 GetViewMatrix() {
        return glm::lookAt(Position, Position + Front, Up);
    }

    void ProcessKeyboard(Camera_Movement direction, float deltaTime) {
        float velocity = MovementSpeed * deltaTime * 30;
        if(direction == FORWARD) {
            Position += Front * velocity;
        }
        if(direction == BACKWARD) {
            Position -= Front * velocity;
        }
        if(direction == LEFT) {
            Position -= Right * velocity;
        }
        if(direction == RIGHT) {
            Position += Right * velocity;
        }
        if(direction == UP) {
            Position += Up * velocity;         
        }
        if(direction == DOWN) {
            Position -= Up * velocity;
        }
        if(direction == PITCHUP) {
            Pitch += 1.0f;
        }
        if(direction == PITCHDOWN) {
            Pitch -= 1.0f;
        }
        if(direction == YAWUP) {
            Yaw += 1.0f;
        }
        if(direction == YAWDOWN) {
            Yaw -= 1.0f;
        }
        if(Pitch > 89.0f)
            Pitch = 89.0;
        if(Pitch < -89.0f)
            Pitch = -89.0f;

        updateCameraVectors();
    }

    void ProcessMouseMovment(float xoffset, float yoffset, GLboolean constrainPitch = true) {
        xoffset *= MouseSensitivity;
        yoffset *= MouseSensitivity;

        Yaw += xoffset;
        Pitch += yoffset;

        // make sure that if pitch is out of bounds, screen doesn't get flipped
        if(constrainPitch) {
            if(Pitch > 89.0f)
                Pitch = 89.0f;
            if(Pitch < -89.0f)
                Pitch = -89.0f;
        }
        // update Front, Right, and Up Vectors using the updated Euler angles
        updateCameraVectors();
    }
    // process input received from a mouse scroll-wheel event.Only requires input on the vertical wheel-axis
    void ProcessMouseScroll(float yoffset) {
        Zoom -= (float) yoffset;
        if(Zoom < 1.0f)
            Zoom = 1.0f;
        if(Zoom > 45.0f)
            Zoom = 45.0f;
    }

private:
    void updateCameraVectors() {
        // calculate the new front vector
        glm::vec3 front;
        front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
        front.y = sin(glm::radians(Pitch));
        front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
        Front = glm::normalize(front);
        // also re-calculate the Right and Up vector
        // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
        Right = glm::normalize(glm::cross(Front, WorldUp));
        Up = glm::normalize(glm::cross(Right, Front));    
    }
};
#endif