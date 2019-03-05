package com.example.roomapp;

import android.app.Application;
import android.os.AsyncTask;

import java.util.List;

import androidx.lifecycle.LiveData;

public class WordRepository {
    private WordDao mWordDao;
    private LiveData<List<Word>> mAllWords;

    public WordRepository(Application application) {
        WordRoomDatabase db=WordRoomDatabase.getDatabase(application);
        mWordDao=db.wordDao();
        mAllWords=mWordDao.getAllWords();
    }

    LiveData<List<Word>> getAllWords() {
        return mAllWords;
    }
    
    public void insert (Word word) {
        new insertASyncTask(mWordDao).execute(word);
    }

    private static class insertASyncTask extends AsyncTask<Word,Void, Void> {

        private WordDao mAsyncTaskDao;

        public insertASyncTask(WordDao dao) {
            mAsyncTaskDao=dao;
        }

        @Override
        protected Void doInBackground(final Word... words) {
            mAsyncTaskDao.insert(words[0]);
            return null;
        }
    }


}
