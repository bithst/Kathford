<?php
// File name is used as class name. Each class to its own file.
// This is just an example

// Class creation
class intro {
    private $var = 'Value';
    
    public function fun() {
        echo 'Statement : ' . $this->var . '<br>';
    }
    
    public function sum($x, $y) {
        echo 'Sum = ' . ($x + $y) . '<br>';
    }
    
    public function ret() {
        return $this->var;
    }
}

// Class with constructor
class construct {
    public $var;
    
    // Runs when object of the class is created
    public function __construct() {
        $this->var = 'Initial value';
    }
    
    // Runs when the class is no longer used
    public function __destruct() {
        echo 'Object destroyed' . '<br>';
    }
}

// Static class
class staticFun {
    static $var = 'Static text';
    
    static function ret() {
        return self::$var;
    }
}

// Abstract class
abstract class abstractClass {
    abstract function out();
}

// Child class
class childClass extends abstractClass {
    public function out() {
        echo 'Output from child class whose parent class is a abstract class.' . '<br>';
    }
} 

// Exception handling
class exceptionFun {
    public function test($x) {
        if($x == 0) {
            throw new Exception('Example exception');
        }
    }
}

// Initializing object of class
$obj = new intro;

// Accessing function members of the class
$obj->fun();
$obj->sum(12, 34);

// Return function
$var = $obj->ret();
echo 'Value inside class = ' . $var . '<br>';

// Using static class
$var = staticFun::ret();
echo 'Value inside static = ' . $var . '<br>';

// Exception handling
/*try {
    $obj = new exceptionFun;
    $var = $obj.test(0);
}
catch (new Exception($x)) {
    
}*/

// Using the child class
$obj = new childClass;
$obj->out();

// Using class with constructor and destructor
$obj = new construct;
echo 'Value in function at creation : ' . $obj->var . '<br>';

?>
