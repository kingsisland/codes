package com.example.roomapp;

import java.util.List;

import androidx.lifecycle.LiveData;
import androidx.room.Dao;
import androidx.room.Database;
import androidx.room.Insert;
import androidx.room.Query;

@Dao
public interface WordDao {

    @Insert
    void insert(Word word);

    @Query("DELETE FROM word_table")
    void deleteAll();

    @Query("SELECT * FROM word_table ORDER BY word ASC")
    LiveData<List<Word>> getAllWords();
}
