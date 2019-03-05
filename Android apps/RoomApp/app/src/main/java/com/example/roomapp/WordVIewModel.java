package com.example.roomapp;

import android.app.Application;

import java.util.List;

import androidx.lifecycle.LiveData;
import androidx.lifecycle.ViewModel;

public class WordVIewModel extends ViewModel {
    private LiveData<List<Word>> mAllWords;
    private WordRepository mWordRepository;

    public WordVIewModel(Application application) {
        super();
        mWordRepository = new WordRepository(application);
        mAllWords=mWordRepository.getAllWords();
    }

    public void insert(Word word){ mWordRepository.insert(word); }

    LiveData<List<Word>> getAllWords() { return mAllWords;}


}
