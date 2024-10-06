using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Laser_collider : MonoBehaviour
{
    private GameObject Playr;
    private GameObject Playr2;
    private Vector3 pos1;
    private Vector3 pos2;
    void Start()
    {
        Playr = GameObject.Find("Player");
        Playr2 = GameObject.Find("Player2");
    }

    void OnTriggerEnter(Collider other){
        if (other.name == "Player"){
            Playr.transform.position = new Vector3(Playr.transform.position.x,Playr.transform.position.y,0);
        }
        else if (other.name == "Player2"){
            Playr2.transform.position = new Vector3(Playr2.transform.position.x,Playr2.transform.position.y,0);
        }
    }
}
