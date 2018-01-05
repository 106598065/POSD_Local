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

    if(evaluate()) {
      if( _left->symbol() == _right->symbol()) {
        return "true";
      }
      return _left->symbol() + " = " + _right->value();
    }
    else {
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
    string output;
    bool inside = false;
    //std::vector<string>::iterator s_it = _s.begin();
    cout <<"HHHHHELO"<< endl;
    if(evaluate()){
      cout <<"evaluate success"<< endl;
      for(std::vector<string>::iterator s_it = _s.begin(); s_it != _s.end(); ++s_it){
        cout <<"inside for"<< endl;
        inside = true;
        if(s_it == _s.end()){
          cout <<"s_it == _s.end() success"<< endl;
          _s.push_back(_left->getExpressionResult());
          output += _left->getExpressionResult();
        }
        if("(*s_it)" == _left->getExpressionResult()){
          break;
        }
      }
      if(!inside){
        _s.push_back(_left->getExpressionResult());

        output += _left->getExpressionResult();
        inside = false;
      }//上面的迴圈並沒有進去, 因此會少left

      MatchExp* pm = dynamic_cast<MatchExp*>(_right);
      if(pm){
        for(std::vector<string>::iterator s_it = _s.begin(); s_it != _s.end(); ++s_it){
          if(s_it == _s.end()){
            _s.push_back(_right->getExpressionResult());
            output += _right->getExpressionResult();
          }
          if((*s_it == _right->getExpressionResult())){
            break;
          }
        }
      }
      //return "123";
      output += ", ";
      return output + _right->getExpressionResult();
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
    return "1";
  }

  bool evaluate() {
    return (_left->evaluate() || _right->evaluate());
  }

private:
  Exp * _left;
  Exp * _right;
};
#endif
