using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AutoSaveGame : MonoBehaviour
{
    public int saveCounter = 1;

    void Update()
    {
        for (int i = 0; saveCounter > i; saveCounter--)
        {
            StartCoroutine(AutoSave());
        }
    }

    IEnumerator AutoSave()
    {
        yield return new WaitForSeconds(10);
        SaveGame.SaveTheGame();
        saveCounter = 1;
    }
}
