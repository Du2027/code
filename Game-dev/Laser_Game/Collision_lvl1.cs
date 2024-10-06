using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Collision_lvl1 : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    void OnTriggerEnter(Collider other){
        if (other.name == "Player"){
            GameObject.Find("Canvas").GetComponent<Menu_manager>().end_levl1();
        }
        else if (other.name == "Player2"){
            GameObject.Find("Canvas").GetComponent<Menu_manager>().end_levl2();
        } 
    }
}
