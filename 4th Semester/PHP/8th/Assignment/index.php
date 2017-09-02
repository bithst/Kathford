<?php

class SMP {
    protected $principle, $time, $rate;
    protected $SI;

    public function takeValue($p, $t, $r) {
        $this->principle = $p;
        $this->time = $t;
        $this->rate = $r;
        $this->SI = $this->calculate();
    }

    protected function calculate() {
        return ($this->principle * $this->time * $this->rate) / 100;
    }

    public function getValue() {
        return $this->SI;
    }
}

$obj = new SMP();
$obj->takeValue(12, 23, 34);

echo 'For P, T and R as 12, 23 and 34 respectively, SI = ' . $obj->getValue(

?>