<?php

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| contains the "web" middleware group. Now create something great!
|
*/

Route::get('/', function () {
    return view('welcome');
});

Route::group(['namespace' => 'Front'], function(){
   Route::any('/', 'ApplicationController@index');
});

Route::get('learn', function() {
   /*return view('Learn.home', [
       'name' => 'you'
   ]);*/

   $f_name = 'Ram';
   $l_name = 'Bahadur';

   return view('Learn.home', compact('f_name', 'l_name'));
});