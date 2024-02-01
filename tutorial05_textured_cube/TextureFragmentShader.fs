#version 330 core 

// Interpolated values from the vertex shaders
in vec2 UV;

//output data 
out vec3 color;

// Values that stay constant for the whole mesh
uniform sampler2D myTextureSampler;

void main(){
    
    //output color = color of the texture at specified UV 
    color= texture(myTextureSampler, UV).rgb;
}