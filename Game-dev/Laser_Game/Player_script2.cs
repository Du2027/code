using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player_script2 : MonoBehaviour
{
    private GameObject Cam;
    private GameObject Player;
    private Rigidbody rb_Player;
    private float pos_z;
    private float[] Force_Array = new float[3];

    public float speed;
    public float cam_offset;
    public float horizontal_speed;
    public float y_force;

    void Start()
    {
        Cam = GameObject.Find("Camera");
        Player = GameObject.Find("Player");
        rb_Player = Player.GetComponent<Rigidbody>();
    }

    void FixedUpdate()
    {
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

        rb_Player.AddForce(new Vector3(Force_Array[0],Force_Array[1],Force_Array[2]));

        pos_z = Player.transform.position.z + cam_offset;
        Cam.transform.position = new Vector3(Cam.transform.position.x,Cam.transform.position.y,pos_z);
    }
}
