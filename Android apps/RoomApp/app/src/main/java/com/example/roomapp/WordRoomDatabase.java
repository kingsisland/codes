package com.example.roomapp;

import android.content.Context;

import androidx.room.Database;
import androidx.room.Room;
import androidx.room.RoomDatabase;


@Database(entities = {Word.class}, version = 1)
public abstract class WordRoomDatabase extends RoomDatabase {

    public abstract WordDao wordDao();

    public static WordRoomDatabase INSTANCE;

    public static WordRoomDatabase getDatabase(final Context context) {
        if (INSTANCE==null) {
            synchronized (WordRoomDatabase.class) {
                if (INSTANCE == null) {
                    //create database here
                    INSTANCE = Room.databaseBuilder(context.getApplicationContext(),
                            WordRoomDatabase.class,"word_database")
                            // Wipes and rebuilds instead of migrating
                            // if no Migration object.
                            // Migration is not part of this practical.
                            .fallbackToDestructiveMigration()

                            .build();
                }
            }
        }
        return INSTANCE;
    }

}
