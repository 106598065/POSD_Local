#ifndef EXP_H
#define EXP_H

#include "atom.h"
#include <vector>
#include <iostream>
using namespace std;

class Exp {
public:
  virtual bool evaluate() = 0;
  virtual string getExpressionResult() = 0;
};


class MatchExp : public Exp {
public:
  MatchExp(Term* left, Term* right): _left(left), _right(right){

  }

  string getExpressionResult() {
    // TEST(Shell, conjunctionMatching_trueAndExp)
    if(evaluate()) {
      if( _left->symbol() == _right->symbol()) {
              //cout<<"FFFALSE1"<<endl;
        return "true";
      }else if( _left->symbol() == _right->value()) {
        //cout<<"FFFALSE2"<<endl;
        return "true";
      }
            //cout<<"FFFALSE3"<<endl;
            //cout<<"_left symbol = "<< _left->symbol()<<"right symbol"<< _right->symbol()<<endl;
      return _left->symbol() + " = " + _right->value();
    }
    else if(!evaluate()) {
      return "false";
    }
  }

  bool evaluate(){
    return _left->match(*_right);
  }

private:
  Term* _left;
  Term* _right;
};

class ConjExp : public Exp {
public:
  ConjExp(Exp *left, Exp *right) : _left(left), _right(right) {

  }

  string getExpressionResult() {
    bool isfind = false;
    string output;
    //std::vector<string>::iterator s_it = _s.begin();
    //cout <<"HHHHHELO"<< endl;
    if(evaluate()){
      // //檢查vector是否為空
      // if(_s.empty()){//vector為空代表沒有塞東西
      //   _s.push_back(_left->getExpressionResult());
      //   output += _left->getExpressionResult();
      // }else{//vector不為空才跑for, 搜尋是否有相同的
      //   isfind = false;
      //   for(std::vector<string>::iterator s_it = _s.begin(); s_it != _s.end(); ++s_it){
      //     if((*s_it) == _left->getExpressionResult()){
      //       isfind = true;
      //       break;
      //     }
      //   }
      //   if(!isfind){
      //       output += ", ";
      //       _s.push_back(_left->getExpressionResult());
      //       output += _left->getExpressionResult();
      //   }
      // }
      //
      // MatchExp* pm = dynamic_cast<MatchExp*>(_right);
      // if(pm){
      //   isfind =  false;
      //   //cout<<"dynamic true"<<endl;
      //   if(_s.begin() == _s.end()) cout<<"right:sbegin == send"<<endl;
      //   for(std::vector<string>::iterator s_it = _s.begin(); s_it != _s.end(); ++s_it){
      //     if((*s_it == _right->getExpressionResult())){
      //       isfind = true;
      //       break;
      //     }
      //   }
      //   if(!isfind){
      //     output += ", ";
      //     _s.push_back(_right->getExpressionResult());
      //     output += _right->getExpressionResult();
      //   }
      // }
      // if (_left->getExpressionResult() == "true"){
      //   return _right->getExpressionResult();
      // }else if (_right->getExpressionResult() == "true" || _left->getExpressionResult().find(_right->getExpressionResult()) != string::npos){
      //   return _left->getExpressionResult();
      // }
      if (_left->getExpressionResult() == "false" || _right->getExpressionResult() == "false"){
        return "false";
      }else if (_right->getExpressionResult() == "true" || _left->getExpressionResult().find(_right->getExpressionResult()) != string::npos){
        return _left->getExpressionResult();
      }else if (_left->getExpressionResult() == "true" && _right->getExpressionResult() == "true"){
        return "true";
      }else if (_left->getExpressionResult() == "true"){
        return _right->getExpressionResult();
      }else{
        return _left->getExpressionResult() + ", " + _right->getExpressionResult();
      }
      return output;// + _right->getExpressionResult();
    }
    else
       return "false";
  }

  bool evaluate() {
    return (_left->evaluate() && _right->evaluate());
  }

private:
  Exp * _left;
  Exp * _right;
  std::vector<string> _s;
  //static std::vector<string> _s;
};

class DisjExp : public Exp {
public:
  DisjExp(Exp *left, Exp *right) : _left(left), _right(right) {

  }

  string getExpressionResult() {
    evaluate();
    if (_right->getExpressionResult() == "false"){
      //cout<<"RIGHT FALSE HERE"<<endl;
      return _left->getExpressionResult();
    }else if (_left->getExpressionResult() == "false"){
      //cout<<"LEFT FALSE HERE"<<endl;
      return _right->getExpressionResult();
    }else{
      return _left->getExpressionResult() + "; " + _right->getExpressionResult();
    }
  }

  bool evaluate() {
    return (_left->evaluate() || _right->evaluate());
  }

private:
  Exp * _left;
  Exp * _right;
};
#endif
