// this is only abstracted because camera movement and camera orientation is needed for EFX and it can get quite repetitive
// and also because it assumes you know how the inner workings work. Right?
namespace LOAL {
  void processInput(GLFWwindow *window) {
          if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {glfwSetWindowShouldClose(window, true);}
           const float camSpeed = static_cast<float>(2.5f * deltaTime);
          if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
                 camPos += camSpeed * camFront;
          }
          if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
                 camPos -= camSpeed * camFront;
          }
          if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
                 camPos -= glm::normalize(glm::cross(camFront, camUp)) * camSpeed;
          }
          if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
                 camPos += glm::normalize(glm::cross(camFront, camUp)) * camSpeed;
    }
  void mouse_callback(GLFWwindow *window, double xpos, double ypos) {
  	if (firstMouse) {
  		std::cout << "mousey moved\n";
  		lastX = xpos;
  		lastY = ypos;
  		firstMouse = 0;
  	}
  
  	float xOffset = xpos - lastX;
  	float yOffset = lastY - ypos;
  	lastX = xpos;
  	lastY = ypos;
  
  	const float sensitivity = 0.1f;
  	xOffset *= sensitivity;
  	yOffset *= sensitivity;
  
  	yaw += xOffset;
  	pitch += yOffset;
  
  	if (pitch > 89.0f)
  		pitch = 89.0f;
  	if (pitch < -89.0f)
  		pitch = -89.0f;
  	glm::vec3 direction;
  	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
  	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
  	direction.y = sin(glm::radians(pitch));
  	camFront = glm::normalize(direction);	
}
}
