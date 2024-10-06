using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player2 : MonoBehaviour
{
    private GameObject Cam;
    private float pos_z;
    private float[] Force_Array = new float[3];

    public float speed;
    public float cam_offset;
    public float y_force;
    public float horizontal_speed;

    void Start()
    {
        Cam = GameObject.Find("Camera");
        
    }

    void FixedUpdate()
    {   if (GameObject.Find("Canvas").GetComponent<Menu_manager>().h_speed != horizontal_speed){
            horizontal_speed = GameObject.Find("Canvas").GetComponent<Menu_manager>().h_speed;
        }
        if (Input.GetKey("d")){
            Force_Array[0] = -horizontal_speed;
        }
        else if(Input.GetKey("a")){
            Force_Array[0] = horizontal_speed;
        }
        else {
            Force_Array[0] = 0.0f;
        }

        Force_Array[1] = y_force;
        Force_Array[2] = -speed;

        GameObject.Find("Player2").GetComponent<Rigidbody>().AddForce(new Vector3(Force_Array[0],Force_Array[1],Force_Array[2]));

        pos_z = GameObject.Find("Player2").transform.position.z + cam_offset;
        
    }
    void LateUpdate(){
        GameObject.Find("Camera").transform.position = new Vector3(GameObject.Find("Camera").transform.position.x,GameObject.Find("Camera").transform.position.y,pos_z);
    }
}
