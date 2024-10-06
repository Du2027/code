using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Play_Button : MonoBehaviour
{/*
    private GameObject Menu;
    private GameObject Levels;

    private GameObject Player;
    private GameObject Pipe1;

    private GameObject Quit;
    private GameObject Play;
    private GameObject Logo;
    private GameObject Backround;
    private GameObject Backround2;
    private GameObject Lvlstxt;
    private GameObject MenuBut;
    Rigidbody Rigidbody_Player;
    GameObject[] Game_Obj_Array = new GameObject[10];

    void Start()
    {
        Menu = GameObject.Find("Menu");
        Levels = GameObject.Find("Levels");

        Player = GameObject.Find("Player");
        Pipe1 = GameObject.Find("Pipe1");

        Quit = GameObject.Find("Quit");
        Logo = GameObject.Find("Logo");
        Backround = GameObject.Find("Backround");
        Play = GameObject.Find("Play");

        Backround2 = GameObject.Find("Backround2");
        Lvlstxt = GameObject.Find("Levels-txt");
        MenuBut = GameObject.Find("Menu-Button");

        int x = 0;
        for (int i = 1;i < 11; i++){
            Game_Obj_Array[x] = GameObject.Find("Level " + i);
            x++;
        }

        for (int i = 0; i < 10; i++){
        Game_Obj_Array[i].SetActive(false);
        }
        Backround2.SetActive(false);
        Lvlstxt.SetActive(false);
        MenuBut.SetActive(false);

        Player.SetActive(false);
        Pipe1.SetActive(false);
    }

    public void Unload_from_Menu(){
        Quit.SetActive(false);
        Logo.SetActive(false);
        Play.SetActive(false);
        Backround.SetActive(false);
        for (int i = 0; i < 10; i++){
            Game_Obj_Array[i].SetActive(true);
        }

        Backround2.SetActive(true);
        MenuBut.SetActive(true);
        Lvlstxt.SetActive(true);

    }

    public void load_lvl_1(){
        for (int i = 0; i < 10; i++){
            Game_Obj_Array[i].SetActive(false);
        }

        Backround2.SetActive(false);
        MenuBut.SetActive(false);
        Lvlstxt.SetActive(false);
    
        Player.SetActive(true);
        Pipe1.SetActive(true);

        //Rigidbody_Player.AddForce(0,0,10,ForceMode.Force);
    }

    public void Load_from_Levels(){
        for (int i = 0; i < 10; i++){
        Game_Obj_Array[i].SetActive(false);
        }
        Backround2.SetActive(false);
        Lvlstxt.SetActive(false);
        MenuBut.SetActive(false);

        Logo.SetActive(true);
        Backround.SetActive(true);
        Quit.SetActive(true);
        Play.SetActive(true);
    }

    public void Quit_Game(){
        Application.Quit();
        Debug.Log("Exiting");
    }
    */
}
