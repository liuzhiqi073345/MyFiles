/***************************************************************************
 * 
 * Copyright (c) 2011 Baidu.com, Inc. All Rights Reserved
 * $Id: config.js 5132 2011-07-05 09:10:56Z liyubei $ 
 * 
 **************************************************************************/
 
 
 
/**
 * config.js ~ 2011/07/04 18:43:13
 * @author leeight(liyubei@baidu.com)
 * @version $Revision: 5132 $ 
 * @description 
 *  
 **/

/**
 * @type {Object}
 */
var CONFIG = {
};

/**
 * @type {Array.<{{text:string,value:string}}> hash ��Ҫ���ҵ�����Դ
 * @type {string} key ��Ҫ�Ƚϵ�ֵ
 *
 * @return {string}
 */
function find_value(hash, key) {
  for(var i = 0, j = hash.length; i < j; i ++) {
    if (hash[i].text == key) {
      return hash[i].value;
    }
  }

  throw new Error("can't find key = [" + key + "]");
}

/**
 * ע����õĽ��
 * @param {string} purpose ��;.
 * @param {string} vediocard �Կ����.
 * @param {string} personality ���Ի�����.
 * @param {string} price �۸�.
 * @param {*} description ������Ϣ.
 */
function add_config(purpose, vediocard, personality, price, description) {
  var key = [
    find_value(PURPOSE_DATA, purpose),
    find_value(VEDIOCARD_DATA, vediocard),
    find_value(PERSONALITY_DATA, personality),
    find_value(PRICE_DATA, price)
  ].join('/');

  CONFIG[key] = description;
}

/**
 * ���ÿ���̫���ӵ������.
 * @return {boolean}
 */
function type_is_string(obj) {
  return typeof obj == 'string';
}

/**
 * ע����õĽ��
 * @param {Array.<string>|string} purposes ��;.
 * @param {Array.<string>|string} vediocards �Կ����.
 * @param {Array.<string>|string} personalitys ���Ի�����.
 * @param {Array.<string>|string} prices �۸�.
 * @param {*} description ������Ϣ.
 */
function add_batch_config(purposes, vediocards, personalitys, prices, description) {
  for(var a = 0; a < purposes.length; a ++) {
    for (var b = 0; b < vediocards.length; b ++) {
      for (var c = 0; c < personalitys.length; c ++) {
        for (var d = 0; d < prices.length; d ++ ) {
          add_config(purposes[a], vediocards[b], personalitys[c], prices[d], description);
        }
      }
    }
  }
}

(function(){
var pc_inspiron_mini10 = [
  "Inspiron Mini10",
  "3Сʱ30��������,250GӲ��,1.37KG,����������ѡ.",
  "http://china.dell.com/cn/p/inspiron-mini1018/pd?c=cn&cs=cndhs1&l=zh&s=dhs&~ck=mn",
  "thumbnail/Ins_Mini10.jpg"
];

var pc_inspiron_m102z = [
  "Inspiron M102z",
  "1.56KG,�ᱡ��Я,4������ɫ��,DDR3�ڴ�.",
  "http://china.dell.com/cn/p/inspiron-m102z/pd.aspx?c=cn&cs=cndhs1&l=zh&s=dhs&~ck=mn",
  "thumbnail/Ins_M102z.jpg"
];

var pc_inspiron_15r = [
  "Inspiron 15R",
  "ǿ���Կ�,������Ӳ��,WIFI��ʱ����,���ֲʿǹ�ѡ.",
  "http://china.dell.com/cn/p/inspiron-15r/pd.aspx?c=cn&cs=cndhs1&l=zh&s=dhs&~ck=mn",
  "thumbnail/Ins_15R.jpg"
];

var pc_inspiron_14r = [
  "Inspiron 14R",
  "ǿ���Կ�,������Ӳ��,WIFI��ʱ����,���ֲʿǹ�ѡ.",
  "http://china.dell.com/cn/p/inspiron-14r-n4110/pd?refid=inspiron-14r-n4110&s=dhs&cs=cndhs1&baynote_bnrank=0&baynote_irrank=1&~ck=dellSearch",
  "thumbnail/Ins_14R.jpg"
]

var pc_vostro_v130 = [
  "Vostro V130",
  "���ᱡѤ��ʱ�л���,�ƶ�����Я������ѡ.",
  "http://china.dell.com/cn/business/p/vostro-v130/fs.aspx?c=cn&cs=cnbsd1&l=zh&s=bsd&~ck=mn",
  "thumbnail/vostro_v130.jpg"
];

var pc_latitude_2120 = [
  "Latitude 2120",
  "�������,��������ҵ��������",
  "http://china.dell.com/cn/business/p/latitude-2120/pd.aspx?c=cn&cs=cnbsd1&l=zh&s=bsd&~ck=mn",
  "thumbnail/latitude-2120.jpg"
];
	
var pc_vostro_3400 = [
  "Vostro 3400",
  "ӵ�и��Ի���,����Ӳ�̵�С����ҵ��Я�ʼǱ�",
  "http://china.dell.com/cn/business/p/vostro-3400/pd?refid=vostro-3400&s=bsd&cs=cnbsd1&~lt=popup#Overview",
  "thumbnail/vostro_3400.jpg"
];

var pc_vostro_v3450 = [
  "Vostro V3450",
  "��Ч���,��Ʒ�ʰ�ȫ�����ƶ��칫�������",
  "http://china.dell.com/cn/business/p/vostro-3450/pd?refid=vostro-3450&s=bsd&cs=cnbsd1&~lt=popup#Overview",
  "thumbnail/vostro_3450.jpg"
];

var pc_vostro_v3550 = [
  "Vostro V3550",
  "��Ʒ�ʰ�ȫ�����ƶ��칫,15��רҵ�ʼǱ�����",
  "http://china.dell.com/cn/business/p/vostro-3550/fs?c=cn&cs=cnbsd1&l=zh&s=bsd&~ck=mn",
  "thumbnail/vostro_3550.jpg"
];

var pc_vostro_v3750 = [
  "Vostro V3750",
  "17.3Ӣ���Ʒ�ʰ�ȫ�칫,̨ʽ���������",
  "http://china.dell.com/cn/business/p/vostro-3750/fs?c=cn&cs=cnbsd1&l=zh&s=bsd&~ck=mn",
  "thumbnail/vostro_3750.jpg"
];

add_config("����", "����", "��ѡ��ɫ", "3000����", pc_inspiron_mini10);
add_config("����", "����", "�������", "3000����", pc_inspiron_mini10);
add_config("����", "����", "����Ӳ��", "3000����", pc_inspiron_mini10);
add_config("����", "����", "ָ��ʶ��", "3000����", pc_inspiron_mini10);
add_config("����", "����", "��ѡ��ɫ", "3000-4000", pc_inspiron_m102z);
add_config("����", "����", "�������", "3000-4000", pc_inspiron_m102z);
add_config("����", "����", "����Ӳ��", "3000-4000", pc_inspiron_m102z);
add_config("����", "����", "ָ��ʶ��", "3000-4000", pc_inspiron_m102z);
add_config("����", "����", "��ѡ��ɫ", "4000-5000", pc_inspiron_m102z);
add_config("����", "����", "�������", "4000-5000", pc_inspiron_m102z);
add_config("����", "����", "����Ӳ��", "4000-5000", pc_inspiron_m102z);
add_config("����", "����", "ָ��ʶ��", "4000-5000", pc_inspiron_m102z);
add_config("����", "����", "��ѡ��ɫ", "5000-6000", pc_inspiron_m102z);
add_config("����", "����", "�������", "5000-6000", pc_inspiron_m102z);
add_config("����", "����", "����Ӳ��", "5000-6000", pc_inspiron_m102z);
add_config("����", "����", "ָ��ʶ��", "5000-6000", pc_inspiron_m102z);
add_config("����", "����", "��ѡ��ɫ", "6000����", pc_inspiron_m102z);
add_config("����", "����", "�������", "6000����", pc_inspiron_m102z);
add_config("����", "����", "����Ӳ��", "6000����", pc_inspiron_m102z);
add_config("����", "����", "ָ��ʶ��", "6000����", pc_inspiron_m102z);
add_config("����", "����", "��ѡ��ɫ", "3000����", pc_inspiron_m102z);
add_config("����", "����", "�������", "3000����", pc_inspiron_m102z);
add_config("����", "����", "����Ӳ��", "3000����", pc_inspiron_m102z);
add_config("����", "����", "ָ��ʶ��", "3000����", pc_inspiron_m102z);
add_config("����", "����", "��ѡ��ɫ", "3000-4000", pc_inspiron_m102z);
add_config("����", "����", "�������", "3000-4000", pc_inspiron_m102z);
add_config("����", "����", "����Ӳ��", "3000-4000", pc_inspiron_m102z);
add_config("����", "����", "ָ��ʶ��", "3000-4000", pc_inspiron_m102z);
add_config("����", "����", "��ѡ��ɫ", "4000-5000", pc_inspiron_15r);
add_config("����", "����", "�������", "4000-5000", pc_inspiron_15r);
add_config("����", "����", "����Ӳ��", "4000-5000", pc_inspiron_15r);
add_config("����", "����", "ָ��ʶ��", "4000-5000", pc_inspiron_15r);
add_config("����", "����", "��ѡ��ɫ", "5000-6000", pc_inspiron_14r);
add_config("����", "����", "�������", "5000-6000", pc_inspiron_14r);
add_config("����", "����", "����Ӳ��", "5000-6000", pc_inspiron_14r);
add_config("����", "����", "ָ��ʶ��", "5000-6000", pc_inspiron_14r);
add_config("����", "����", "��ѡ��ɫ", "6000����", pc_inspiron_14r);
add_config("����", "����", "�������", "6000����", pc_inspiron_14r);
add_config("����", "����", "����Ӳ��", "6000����", pc_inspiron_14r);
add_config("����", "����", "ָ��ʶ��", "6000����", pc_inspiron_14r);
add_config("����", "����", "��ѡ��ɫ", "3000����", pc_inspiron_14r);
add_config("����", "����", "�������", "3000����", pc_inspiron_14r);
add_config("����", "����", "����Ӳ��", "3000����", pc_inspiron_14r);
add_config("����", "����", "ָ��ʶ��", "3000����", pc_inspiron_14r);
add_config("����", "����", "��ѡ��ɫ", "3000-4000", pc_inspiron_14r);
add_config("����", "����", "�������", "3000-4000", pc_inspiron_14r);
add_config("����", "����", "����Ӳ��", "3000-4000", pc_inspiron_14r);
add_config("����", "����", "ָ��ʶ��", "3000-4000", pc_inspiron_14r);
add_config("����", "����", "��ѡ��ɫ", "4000-5000", pc_vostro_v130);
add_config("����", "����", "�������", "4000-5000", pc_latitude_2120);
add_config("����", "����", "����Ӳ��", "4000-5000", pc_vostro_v130);
add_config("����", "����", "ָ��ʶ��", "4000-5000", pc_vostro_v130);
add_config("����", "����", "��ѡ��ɫ", "5000-6000", pc_vostro_v130);
add_config("����", "����", "�������", "5000-6000", pc_vostro_v130);
add_config("����", "����", "����Ӳ��", "5000-6000", pc_vostro_v130);
add_config("����", "����", "ָ��ʶ��", "5000-6000", pc_vostro_v130);
add_config("����", "����", "��ѡ��ɫ", "6000����", pc_vostro_v130);
add_config("����", "����", "�������", "6000����", pc_vostro_v130);
add_config("����", "����", "����Ӳ��", "6000����", pc_vostro_v130);
add_config("����", "����", "ָ��ʶ��", "6000����", pc_vostro_v130);
add_config("����", "����", "��ѡ��ɫ", "3000����", pc_vostro_v130);
add_config("����", "����", "�������", "3000����", pc_vostro_v130);
add_config("����", "����", "����Ӳ��", "3000����", pc_vostro_v130);
add_config("����", "����", "ָ��ʶ��", "3000����", pc_vostro_v130);
add_config("����", "����", "��ѡ��ɫ", "3000-4000", pc_vostro_v130);
add_config("����", "����", "�������", "3000-4000", pc_vostro_v130);
add_config("����", "����", "����Ӳ��", "3000-4000", pc_vostro_v130);
add_config("����", "����", "ָ��ʶ��", "3000-4000", pc_vostro_v130);
add_config("����", "����", "��ѡ��ɫ", "4000-5000", pc_vostro_3400);
add_config("����", "����",	"�������",	"4000-5000", pc_vostro_3400);
add_config("����", "����",	"����Ӳ��",	"4000-5000", pc_vostro_3400);
add_config("����", "����", "ָ��ʶ��", "4000-5000",	pc_vostro_3400);
add_config("����", "����", "��ѡ��ɫ", "5000-6000",	pc_vostro_v3450);
add_config("����", "����", "�������", "5000-6000",	pc_vostro_v3450);
add_config("����", "����", "����Ӳ��", "5000-6000",  pc_vostro_v3450);
add_config("����", "����", "ָ��ʶ��", "5000-6000",	pc_vostro_v3450);
add_config("����", "����", "��ѡ��ɫ", "6000����", pc_vostro_v3550);
add_config("����", "����", "�������", "6000����", pc_vostro_v3550);
add_config("����", "����", "����Ӳ��", "6000����", pc_vostro_v3750);
add_config("����", "����", "ָ��ʶ��", "6000����", pc_vostro_v3750);

})();


















/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
