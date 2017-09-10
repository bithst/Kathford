<?php

namespace App\Http\Controllers\Front;

use Illuminate\Http\Request;
use App\Http\Controllers\Controller;

class FrontController extends Controller
{
    protected $pagePath = 'Front/';

    public $page;

    public function __construct() {
        $this->page = $this->pagePath . 'Pages/';
    }
}
