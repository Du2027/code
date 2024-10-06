using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class Menu_manager : MonoBehaviour
{
    private GameObject Main_Menu;
    private GameObject Level_Menu;
    private GameObject Level1;
    private GameObject Lvl_after;
    private GameObject Level2;
    private int nö = 0;
    private int nö2 = 0;
    private int Button_pressed = 0;
    private GameObject Hard_txt;
    private TMP_Text txt;
    public float h_speed;

    private void reset_obj(float Z_cord, GameObject Obj){
        Obj.transform.position = new Vector3(Obj.transform.position.x,Obj.transform.position.y,Z_cord);
    }

    void Start()
    {
        h_speed = this.GetComponentInChildren<Player2>().horizontal_speed;
        Hard_txt = GameObject.Find("Hard_activated");
        txt = Hard_txt.GetComponent<TextMeshProUGUI>();

        Main_Menu = GameObject.Find("Menu");
        Level_Menu = GameObject.Find("Levels");
        Level1 = GameObject.Find("Lvl1");
        Level2 = GameObject.Find("Lvl1 2");
        Lvl_after = GameObject.Find("Lvl_done");

        Level_Menu.SetActive(false);
        Level1.SetActive(false);
        Lvl_after.SetActive(false);
        Level2.SetActive(false);
    }

    void Update()
    {
        
    }
    public void Level2_load(){
        nö2 += 1;
        if (nö2 == 1){
        Level_Menu.SetActive(false);
        Level2.SetActive(true);}
    }
    public void Menu_from_end(){
        Lvl_after.SetActive(false);
        Main_Menu.SetActive(true);
    }
    public void Levels_from_end(){
        Lvl_after.SetActive(false);
        Level_Menu.SetActive(true);
    }
    public void end_levl1(){
        Lvl_after.SetActive(true);
        Level1.SetActive(false);
    }
    public void end_levl2(){
        Lvl_after.SetActive(true);
        Level2.SetActive(false);
    }

    public void levels_from_main(){
        Main_Menu.SetActive(false);
        Level_Menu.SetActive(true);
    }

    public void level1_from_levels(){
        nö += 1;
        if (nö == 1){
        Level_Menu.SetActive(false);
        Level1.SetActive(true);}
    }

    public void main_menu_from_Lvls(){
        Main_Menu.SetActive(true);
        Level_Menu.SetActive(false);
    }

    public void Quit_Game(){
        Application.Quit();
    }

    public void Hard_Mode(){
        Button_pressed += 1;
        if (Button_pressed == 1){
            txt.text = "Hard Mode is active";
            h_speed = 500f;
        }
        else {
            Button_pressed = 0;
            txt.text = "";
        }
    }
}