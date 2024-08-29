#version 330 core
out vec4 FragColor;

in VS_OUT{
    vec3 FragPos;
	vec3 Normal;
	vec2 TexCoords;
    vec3 Color;
} fs_in;

// uniform vec3 objectColor;
uniform vec3 lightPos;
uniform vec3 viewPos;
uniform bool blinn;
uniform bool shader;
uniform bool ifTex;
// texture sampler
uniform sampler2D tex0;

vec3 CameraLight();

// function prototypes
void main()
{
    if(shader){
        // compute the light
        vec3 result = CameraLight();

        if(ifTex) {
            FragColor = texture2D(tex0, fs_in.TexCoords);
        }
        else {
            FragColor = vec4(result, 1.0);  
        }
    }
    else {
        FragColor = vec4(fs_in.Color, 1.0);
    }
}
// camera light
vec3 CameraLight()
{
    // ambient
    vec3 ambient = 0.05 * fs_in.Color;
    // diffuse
    vec3 lightDir = normalize(lightPos - fs_in.FragPos);
    vec3 normal = normalize(fs_in.Normal);
    float diff = max(dot(lightDir, normal), 0.0);
    vec3 diffuse = diff * fs_in.Color;
    // specular
    vec3 viewDir = normalize(viewPos - fs_in.FragPos);
    //reflect(): 入射光 - 2.0 * normal * <normal, 入射光>
    // 入射光 =  - 1 * lightDir
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = 0.0;
    if(blinn){
        vec3 halfwayDir = normalize(lightDir + viewDir);  
        spec = pow(max(dot(normal, halfwayDir), 0.0), 32.0);
    }
    else {
        vec3 reflectDir = reflect(-lightDir, normal);
        spec = pow(max(dot(viewDir, reflectDir), 0.0), 8.0); // n = 8 Ks = 0.3 => 瓷器
    }
    vec3 specular = vec3(0.3) * spec; // assuming bright white light color
    return (ambient + diffuse + specular);
}