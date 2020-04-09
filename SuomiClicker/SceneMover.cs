using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class SceneMover : MonoBehaviour
{

    public static bool StartToMain = false;

    void Start()
    {
        if (StartToMain == false)
        {
            StartToMain = true;
            StartCoroutine(LoadMain());
        }
        else
        {

        }
    }

    IEnumerator LoadMain()
    {
        yield return new WaitForSeconds(3);
        SceneManager.LoadScene(1);
    }

    public void GoStart()
    {
        SaveGame.DeleteSave();
        StartToMain = false;
        SceneManager.LoadScene(0);
    }

    public void GoMain()
    {
        SceneManager.LoadScene(1);
        SaveGame.SaveTheGame();
    }

    public void GoUpgrade()
    {
        SceneManager.LoadScene(2);
        SaveGame.SaveTheGame();
    }

    public void GoInvest()
    {
        SceneManager.LoadScene(3);
        SaveGame.SaveTheGame();
    }

    public void GoShop()
    {
        SceneManager.LoadScene(4);
        SaveGame.SaveTheGame();
    }

    public void GoGambling()
    {
        SceneManager.LoadScene(5);
        SaveGame.SaveTheGame();
    }

    public void GoSettings()
    {
        SceneManager.LoadScene(6);
        SaveGame.SaveTheGame();
    }

    public void GoDictionary()
    {
        SceneManager.LoadScene(7);
        SaveGame.SaveTheGame();
    }


}
